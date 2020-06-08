#ifndef HESTIA_GRAPHICS_MATERIAL_MATERIAL_H
#define HESTIA_GRAPHICS_MATERIAL_MATERIAL_H

#define GLM_FORCE_SILENT_WARNINGS

#include "glad/glad.h"
#include "glm/glm.hpp"

#include "maths/maths_types.h"

namespace HGE {

    using TextureId = unsigned int;

    struct Material {
        TextureId mId;

        explicit Material(TextureId id) : mId(id) { }
        ~Material() = default;

        void useTexture() const {
            glBindTexture(GL_TEXTURE_2D, mId);
        }
    };
}

#endif 