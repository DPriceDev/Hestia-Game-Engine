#ifndef HESTIA_GRAPHICS_SPRITE_COMPONENT_HPP_
#define HESTIA_GRAPHICS_SPRITE_COMPONENT_HPP_

#include <iostream>
#include <vector>
#include "glm/glm.hpp"

#include "../src/framework/ecs/Component.hpp"

#include "../src/maths/MathsTypes.hpp"
#include "../src/graphics/shaders/Shader.hpp"

#include "../src/util/Logger.hpp"

namespace HGE {

    struct SpriteComponent : public Component {
        
        glm::vec3 mLocalPosition;
        Shader* mShader;
        Transform2f mTransform;

        SpriteComponent() : Component("Sprite") {
            LogDebug("Sprite Component Created");
            mLocalPosition = glm::vec3(0.0, 0.0, 1.0);
        }

        ~SpriteComponent() { }

        void registerSystem() override;

        // void setWidth(float width);
        // void setHeight(float height);
        // void setWidthAndHeight(float width, float height);
    };
}

#endif