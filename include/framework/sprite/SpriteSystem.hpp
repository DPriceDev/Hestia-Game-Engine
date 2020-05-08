#ifndef HESTIA_FRAMEWORK_SPRITE_SYSTEM_HPP_
#define HESTIA_FRAMEWORK_SPRITE_SYSTEM_HPP_

#include <vector>
#include "glm/glm/glm.hpp"

#include "framework/ecs/System.hpp"
#include "framework/ecs/ComponentManager.hpp"
#include "framework/sprite/SpriteComponent.hpp"

#include "graphics/GraphicsModule.hpp"

#include "util/Logger.hpp"

namespace HGE {
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