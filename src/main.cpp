/**
 * Copyright D. price 2020.
 */

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

/* Const Values */

/* Global Variables */

/* Function Declarations */
void framebufferSizeCallback(GLFWwindow* window, int width, int height);

/* Main Entry Point. */
int main(void) 
{
    std::cout << "Program Begin" << std::endl;

    /* Initialize GLFW and set the window params. */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    /* Initialize the window and apply it as the current GLFW context. add window resize callback. */
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);  

    /* If the window is not created, log and return error. Also terminate GLFW. */
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* If GLAD library is not loaded, log and return error. Also terminate GLFW. */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -1;
    } 

    /* Set the initial window size. */
    glViewport(0, 0, 800, 600);
    std::cout << "Window Initialized" << std::endl;

    /* Main Loop whilst window is open. */
    while(!glfwWindowShouldClose(window))
    {
        /* Game Logic */

        /* Draw Logic */

        /* clear screen and load new buffer. */
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        
        /* check and execute callbacks for events. */
        glfwPollEvents();    
    }

    /* Log window closed and terminate the program. */
    printf("Window Closed\n");
    glfwTerminate();
    return 0;
}

/** 
 * FrameBuffer Size Callback
 */
void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}