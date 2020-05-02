#ifndef HESTIA_GRAPHICS_SPRITE_SYSTEM_HPP_
#define HESTIA_GRAPHICS_SPRITE_SYSTEM_HPP_

#include <iostream>
#include <vector>
#include "glm/glm/glm.hpp"

#include "framework/ecs/System.hpp"
#include "framework/ecs/Component.hpp"

#include "util/Logger.hpp"

#include "framework/sprite/SpriteComponent.hpp"
#include "graphics/GraphicsModule.hpp"

namespace HGE {

    class SpriteSystem : public System {

        private:
        std::vector<Component*>* mComponents;
        GraphicsModule* mGraphicsModule;
        unsigned int mSpriteVao, mSpriteVbo;
        glm::mat4 mOrthographic;

        public:
        SpriteSystem();

        ~SpriteSystem() { }

        void run() override;
    };
}

#endif