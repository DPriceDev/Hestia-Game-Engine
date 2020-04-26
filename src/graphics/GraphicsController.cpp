#include "GraphicsController.hpp"

/** 
 * FrameBuffer Size Callback
 */
void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

/**
 * 
 */
GraphicsController::GraphicsController()
{
    //glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);
}