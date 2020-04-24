/**
 * Copyright D. price 2020.
 */

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "framework/GameEnvironment.hpp"
#include "framework/InputController.hpp"
#include "graphics/GraphicsController.hpp"
#include "framework/ObjectController.hpp"

/* Function Declarations */
GLFWwindow* OpenGlInit(const char * title, int windowX, int windowY);

/**
 * Main Entry Point.
 */
int main(void) 
{
    /* Initialize openGl Window */
    std::cout << "Program Begin" << std::endl;
    GLFWwindow* window = OpenGlInit("2D Game Engine", 800, 600);

    if(window == nullptr) {
        return -1;
    }

    /* Initialize Controllers and initial game enviroment. */
    InputController inputController = InputController();
    GraphicsController graphicsController = GraphicsController(window); 
    GameEnvironment* gameEnvironment = new GameEnvironment(&inputController, &graphicsController);

    // TODO: Load inital config and get initial level?

    // TODO: Load inital level and init the gameEnvironment
    
    gameEnvironment->Init();

    /* Main Loop whilst window is open. */
    while(!glfwWindowShouldClose(window))
    {
        inputController.processInput(window);
        gameEnvironment->GameLoop();
        graphicsController.Render();
    }

    /* Log window closed and terminate the program. */
    printf("Window Closed\n");
    glfwTerminate();
    return 0;
}

/**
 * OpenGl Initialization
 * 
 * returns true if initialized correctly.
 */
GLFWwindow* OpenGlInit(const char * title, int windowX, int windowY) {

    /* Initialize GLFW and set the window params. */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

   GLFWwindow* window = glfwCreateWindow(800, 600, "title", NULL, NULL);

    /* Initialize the window and apply it as the current GLFW context. add window resize callback. */
    glfwMakeContextCurrent(window);

    /* If the window is not created, log and return error. Also terminate GLFW. */
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        return nullptr;
    }

    /* If GLAD library is not loaded, log and return error. Also terminate GLFW. */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return nullptr;
    } 

    /* Set the initial window size. */
    glViewport(0, 0, windowX, windowY);
    std::cout << "Window Initialized" << std::endl;

    return window;
}