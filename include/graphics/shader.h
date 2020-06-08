#ifndef HESTIA_GRAPHICS_SHADER_H
#define HESTIA_GRAPHICS_SHADER_H

#define GLM_FORCE_SILENT_WARNINGS

#include "glad/glad.h"
#include "glm/glm.hpp"

#include <string>

namespace HGE {
    using ShaderProgram = unsigned int;

    struct Shader {
        ShaderProgram mId;

    public:
        explicit Shader(ShaderProgram id) : mId(id) {}
        ~Shader() = default;
        void useShader() const;

        [[nodiscard]] ShaderProgram getShaderId() const {
            return mId;
        }

        void setBool(const std::string &name, bool value) const;
        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;
        void setVec3(const std::string &name, glm::vec3 &value) const;
        void setVec4(const std::string &name, glm::vec4 &value) const;
        void setMat4(const std::string &name, glm::mat4 &value) const;
    };
}// namespace HGE

#endif