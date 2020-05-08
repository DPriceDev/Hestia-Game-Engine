#include "graphics/Shader.h"

#include <string>

namespace HGE {

    void Shader::useShader() {
        glUseProgram(mId);
    }

    void Shader::setBool(const std::string &name, bool value) const
    {         
        glUniform1i(glGetUniformLocation(mId, name.c_str()), (int)value); 
    }
    void Shader::setInt(const std::string &name, int value) const
    { 
        glUniform1i(glGetUniformLocation(mId, name.c_str()), value); 
    }
    void Shader::setFloat(const std::string &name, float value) const
    { 
        glUniform1f(glGetUniformLocation(mId, name.c_str()), value); 
    } 
    void Shader::setVec4(const std::string &name, glm::vec4 &value) const {
        glUniform4fv(glGetUniformLocation(mId, name.c_str()), 1, &value[0]);
    }
    void Shader::setVec3(const std::string &name, glm::vec3 &value) const {
        glUniform3fv(glGetUniformLocation(mId, name.c_str()), 1, &value[0]);
    }
    void Shader::setMat4(const std::string &name, glm::mat4 &value) const {
        glUniformMatrix4fv(glGetUniformLocation(mId, name.c_str()), 1, GL_FALSE, &value[0][0]);
    }
}
