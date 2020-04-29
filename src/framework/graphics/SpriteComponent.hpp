#ifndef HESTIA_GRAPHICS_SPRITE_COMPONENT_HPP_
#define HESTIA_GRAPHICS_SPRITE_COMPONENT_HPP_

#include <iostream>
#include <vector>

#include "../src/framework/ecs/Component.hpp"

#include "../src/maths/MathsTypes.hpp"
#include "../src/graphics/shaders/Shader.hpp"

#include "../src/util/Logger.hpp"

/**
 * Sprite Component
 */
struct SpriteComponent : public Component {
    
    public:
    Vector2f mVertices[4];
    Shader* mShader;
    unsigned int mVAO, mVBO;

    SpriteComponent() : Component("Sprite") {
        LogDebug("Sprite Component Created");
    }

    ~SpriteComponent() { }

    void registerSystem() override;
};

#endif