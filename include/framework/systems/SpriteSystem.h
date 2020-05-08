#ifndef HESTIA_FRAMEWORK_SPRITE_SYSTEM_H
#define HESTIA_FRAMEWORK_SPRITE_SYSTEM_H

#include <vector>
#include <glm/glm/glm.hpp>

#include "framework/ecs/ecs.h"

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

        ComponentArray<SpriteComponent>* mComponentsArray;
        GraphicsModule* mGraphicsModule;
        unsigned int mSpriteVao, mSpriteVbo;
        glm::mat4 mOrthographic;

        public:
        System(ComponentArray<SpriteComponent>* componentArray);

        ~System() { }

        void run() override {
            for(auto const & component : mComponentsArray->getComponents()) {
                mGraphicsModule->drawSprite(component->mShader, component->mMaterial, mSpriteVao, component->mTransform, component->mTint, component->mAlpha, mOrthographic);
            }
        }
    };
}

#endif