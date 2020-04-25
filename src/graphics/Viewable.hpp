#ifndef GRAPHICS_VIEWABLE_HPP
#define GRAPHICS_VIEWABLE_HPP

#include <vector>
#include <array>

#include "shaders/shader.hpp"

/**
 * 
 */
class Viewable {
    public:
    Viewable() { 
        mVertices = std::vector<float>();
        mVertexShaders = std::vector<Shader*>();
        mFragmentShaders = std::vector<Shader*>();
    }

    ~Viewable() { 
        for(auto & shader : mVertexShaders) {
            delete shader;
        }

        for(auto & shader : mFragmentShaders) {
            delete shader;
        }
    }

    virtual void draw() = 0;

    protected:
    std::vector<Shader*> mVertexShaders;
    std::vector<Shader*> mFragmentShaders;
    std::vector<float> mVertices;
};

#endif