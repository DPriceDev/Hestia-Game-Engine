#ifndef HESTIA_GRAPHICS_SPRITE_COMPONENT_HPP_
#define HESTIA_GRAPHICS_SPRITE_COMPONENT_HPP_

#include <iostream>
#include <vector>
#include "glm/glm/glm.hpp"

#include "../src/framework/ecs/Component.hpp"

#include "../src/maths/MathsTypes.hpp"
#include "../src/graphics/shaders/Shader.hpp"

#include "../src/util/Logger.hpp"

namespace HGE {

    struct SpriteComponent : public Component {
        
        Transform2f mTransform; 
        Shader* mShader;

        SpriteComponent() : Component("Sprite") {
            mTransform = Transform2f();
        }

        ~SpriteComponent() { }

        void registerSystem() override;
    };
}

#endif