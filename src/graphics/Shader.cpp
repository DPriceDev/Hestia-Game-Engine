#include "graphics/Shader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

namespace HGE {

    /* Function Declarations */
    bool checkShaderLoadedCorrectly(unsigned int id);
    bool checkProgramLoadedCorrectly(unsigned int id);

    /**
     * 
     */
    Shader::Shader(const char *vertexShaderPath, const char *fragmentShaderPath) {

        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;

        /* Exceptions */
        vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

        try {
            // open files
            vShaderFile.open(vertexShaderPath);  
            fShaderFile.open(fragmentShaderPath);

            std::stringstream vShaderStream, fShaderStream;
            // read file's buffer contents into streams
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();

            // close file handlers
            vShaderFile.close();
            fShaderFile.close();
            // convert stream into string
            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();

        } catch(std::ifstream::failure e) {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }

        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();

        // 2. compile shaders
        unsigned int vertex, fragment;
        int success;
        char infoLog[512];
        
        // vertex Shader
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        checkShaderLoadedCorrectly(vertex);

        // fragment Shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);
        checkShaderLoadedCorrectly(fragment);
        
        // shader Program
        mId = glCreateProgram();
        glAttachShader(mId, vertex);
        glAttachShader(mId, fragment);
        glLinkProgram(mId);
        checkProgramLoadedCorrectly(mId);
        
        // delete the shaders as they're linked into our program now and no longer necessery
        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    /* Delete shader on destruction. */
    Shader::~Shader() {
        glDeleteProgram(mId);
    }

    /* */
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
    void Shader::setMat4(const std::string &name, glm::mat4 &value) const {
        glUniformMatrix4fv(glGetUniformLocation(mId, name.c_str()), 1, GL_FALSE, &value[0][0]);
    }

    /* Helper Methods */
    bool checkShaderLoadedCorrectly(unsigned int id) {
        int success;
        char infoLog[512];

        glGetShaderiv(id, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(id, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        };
        return success;
    }

    bool checkProgramLoadedCorrectly(unsigned int id) {
        int success;
        char infoLog[512];

        glGetProgramiv(id, GL_LINK_STATUS, &success);
        if(!success)
        {
            glGetProgramInfoLog(id, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        return success;
    }
}