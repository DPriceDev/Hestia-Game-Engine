#ifndef HESTIA_GRAPHICS_SPRITE_COMPONENT_HPP_
#define HESTIA_GRAPHICS_SPRITE_COMPONENT_HPP_

#include <iostream>
#include <vector>

#include "../src/framework/ecs/Component.hpp"

#include "../src/maths/MathsTypes.hpp"
#include "../src/graphics/shaders/Shader.hpp"

#include "../src/util/Logger.hpp"

namespace HGE {

    struct SpriteComponent : public Component {
        
        public:
        float mVertices[8];
        unsigned int mVAO, mVBO;
        Shader* mShader;
        Transform2f mTransform;

        SpriteComponent() : Component("Sprite") {
            LogDebug("Sprite Component Created");
        }

        ~SpriteComponent() { }

        void registerSystem() override;

        void setWidth(float width);
        void setHeight(float height);
        void setWidthAndHeight(float width, float height);
    };
}

#endif