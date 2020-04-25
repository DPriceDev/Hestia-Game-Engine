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
GraphicsController::GraphicsController(GLFWwindow* window) : mWindow(window) 
{
    mViewObjects = std::vector<Viewable*>();
    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);  

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

/**
 * 
 */
void GraphicsController::Render() 
{
    for(auto & viewable : mViewObjects) {
        viewable->draw();
    }

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    
    /* clear screen and load new buffer. */
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(mWindow);
    
    /* check and execute callbacks for events. */
    glfwPollEvents();    
}