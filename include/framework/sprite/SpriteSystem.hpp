#ifndef HESTIA_GRAPHICS_SPRITE_SYSTEM_HPP_
#define HESTIA_GRAPHICS_SPRITE_SYSTEM_HPP_

#include <iostream>
#include <vector>
#include "glm/glm/glm.hpp"

#include "framework/ecs/System.hpp"

#include "util/Logger.hpp"

#include "framework/sprite/SpriteComponent.hpp"
#include "graphics/GraphicsModule.hpp"

namespace HGE {
    template <> 
    class System<SpriteComponent> : public ISystem {

        std::tuple<std::vector<std::unique_ptr<SpriteComponent>>> mComponents;
        GraphicsModule* mGraphicsModule;
        unsigned int mSpriteVao, mSpriteVbo;
        glm::mat4 mOrthographic;

        public:
        System();

        ~System() { }

        void run() override {
            for(auto & component : std::get<std::vector<std::unique_ptr<SpriteComponent>>>(mComponents)) {
                mGraphicsModule->drawSprite(component->mShader, component->mMaterial, mSpriteVao, component->mTransform, component->mTint, component->mAlpha, mOrthographic);
            }
        }
    };
}

#endif