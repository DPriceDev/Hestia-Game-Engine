#ifndef HESTIA_GRAPHICS_OPENGL_MODULE_HPP_
#define HESTIA_GRAPHICS_OPENGL_MODULE_HPP_

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "GraphicsModule.hpp"

/**
 * 
 */
class OpenGlModule : public GraphicsModule {

    private:
    GLFWwindow* mWindow;

    public:
    OpenGlModule() {

    }

    ~OpenGlModule() {

    }

    bool init() override;
};


#endif