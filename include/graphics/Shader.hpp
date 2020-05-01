#ifndef GRAPHICS_SHADER_HPP
#define GRAPHICS_SHADER_HPP

#include "glad/glad.h"
#include "glm/glm/glm.hpp"
#include <string>

namespace HGE {

    struct Shader {

        private:
        unsigned int mId;

        public:
        Shader(const char *vertexShaderPath, const char *fragmentShaderPath);
        ~Shader();

        void useShader();

        unsigned int getShaderId() {
            return mId;
        }

        void setBool(const std::string &name, bool value) const;  
        void setInt(const std::string &name, int value) const;   
        void setFloat(const std::string &name, float value) const;
        void setVec4(const std::string &name, glm::vec4 &value) const;
        void setMat4(const std::string &name, glm::mat4 &value) const;
    };
}

#endif