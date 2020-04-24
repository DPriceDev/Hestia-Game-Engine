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
GraphicsController::GraphicsController(GLFWwindow* window) : mWindow(window) {
    mViewObjects = new std::vector<Object*>();
    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);  
}

/**
 * 
 */
void GraphicsController::Render() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    
    /* clear screen and load new buffer. */
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(mWindow);
    
    /* check and execute callbacks for events. */
    glfwPollEvents();    
}