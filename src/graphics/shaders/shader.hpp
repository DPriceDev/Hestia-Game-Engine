#ifndef GRAPHICS_SHADER_HPP
#define GRAPHICS_SHADER_HPP

#include "glad/glad.h"
#include <string>

namespace HGE {

    struct Shader {

        private:
        unsigned int mId;

        public:
        Shader(const char *vertexShaderPath, const char *fragmentShaderPath);
        ~Shader();

        void useShader();

        void setBool(const std::string &name, bool value) const;  
        void setInt(const std::string &name, int value) const;   
        void setFloat(const std::string &name, float value) const;
    };
}

#endif