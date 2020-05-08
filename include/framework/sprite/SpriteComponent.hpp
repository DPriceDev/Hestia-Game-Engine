#ifndef HESTIA_GRAPHICS_SPRITE_COMPONENT_HPP_
#define HESTIA_GRAPHICS_SPRITE_COMPONENT_HPP_

#include <iostream>
#include <vector>
#include "glm/glm/glm.hpp"

#include "framework/ecs/Component.hpp"

#include "maths/MathsTypes.hpp"
#include "graphics/Shader.hpp"
#include "graphics/Material.hpp"

#include "util/Logger.hpp"

namespace HGE {

    struct SpriteComponent : public Component {
        
        Transform2f mTransform; 
        Shader* mShader;
        Material* mMaterial;
        ColourRGBA mTint;
        Pointf mAlpha;

        SpriteComponent(UID ownerId);
        ~SpriteComponent();
    };
}

#endif