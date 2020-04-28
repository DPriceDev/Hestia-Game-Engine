#ifndef HESTIA_GRAPHICS_OPENGL_MODULE_HPP_
#define HESTIA_GRAPHICS_OPENGL_MODULE_HPP_

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <vector>

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
    void terminate() override;

    bool isWindowOpen() override;

    void renderFrame() override;
    void drawTriangle(std::vector<Vector2f>* pVertices, Shader* pShader) override;
    void startFrame() override;
};


#endif