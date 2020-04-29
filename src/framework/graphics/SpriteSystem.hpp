#ifndef HESTIA_GRAPHICS_SPRITE_SYSTEM_HPP_
#define HESTIA_GRAPHICS_SPRITE_SYSTEM_HPP_

#include <iostream>
#include <vector>

#include "../src/framework/ecs/System.hpp"
#include "../src/framework/ecs/Component.hpp"

#include "../src/util/Logger.hpp"

#include "SpriteComponent.hpp"
#include "../src/graphics/GraphicsModule.hpp"

namespace HGE {

    class SpriteSystem : public System {

        private:
        std::vector<Component*>* mComponents;
        GraphicsModule* mGraphicsModule;

        public:
        SpriteSystem();

        ~SpriteSystem() {
        }

        void run() override;
    };
}

#endif