#ifndef HESTIA_FRAMEWORK_SPRITE_SYSTEM_H
#define HESTIA_FRAMEWORK_SPRITE_SYSTEM_H

#include <vector>
#include <glm/glm/glm.hpp>


#include "framework/ecs/ComponentManager.h"
#include "framework/systems/WorldPositionSystem.h"
#include "framework/ecs/Component.h"
#include "framework/ecs/System.h"

#include "graphics/GraphicsModule.h"

#include "util/Logger.h"

namespace HGE {

    /**
     * Sprite Component
     */
    struct SpriteComponent : public Component {
        
        Transform2f mTransform; 
        Shader* mShader;
        Material* mMaterial;
        ColourRGBA mTint;
        Pointf mAlpha;

        SpriteComponent(UID ownerId) : Component(ownerId), mTransform(Transform2f()), mTint(ColourRGBA()), mAlpha(1.0f) { }
        ~SpriteComponent() = default;
    };

    /**
     * Sprite System
     */
    template <> 
    class System<SpriteComponent> : public ISystem {

        ComponentManager* mComponentManager;
        ComponentArray<SpriteComponent>* mSpritesArray;
        ComponentArray<WorldPositionComponent>* mPositionsArray;
        GraphicsModule* mGraphicsModule;
        unsigned int mSpriteVao, mSpriteVbo;
        glm::mat4 mOrthographic;

        public:
        System(ComponentArray<SpriteComponent>* componentArray);

        ~System() { }

        void run() override {
            for(auto const & component : mSpritesArray->getComponents()) {
                auto worldComponent = mPositionsArray->getComponentWithOwner(component->getOwnerUID());
                
                if(worldComponent != nullptr) {
                    mGraphicsModule->drawSprite(component->mShader, component->mMaterial, mSpriteVao, component->mTransform, worldComponent->mTransform, component->mTint, component->mAlpha, mOrthographic);
                } else {
                    Logger::getInstance()->logDebug("Sprite System", " No Position component available for object!");
                }
            }
        }
    };
}

#endif