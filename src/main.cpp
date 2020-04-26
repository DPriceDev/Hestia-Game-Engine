/**
 * Copyright D. price 2020.
 */

#include <iostream>

#include "framework/Engine.hpp"
#include "framework/GameEnvironment.hpp"
#include "framework/InputController.hpp"
#include "graphics/GraphicsController.hpp"

/* Function Declarations */
GLFWwindow* OpenGlInit(const char * title, int windowX, int windowY);
Engine *Engine::mEngine;

/**
 * Main Entry Point.
 */
int main(void) 
{
    /* Initialize openGl Window */
    std::cout << "Program Begin" << std::endl;

    Engine* engine = engine->getInstance();

    if(!engine->Init()) {
        return -1;
    }

    GraphicsController graphicsController(engine->getWindow());

    GameEnvironment* gameEnvironment = new GameEnvironment();

    // TODO: Load inital config and get initial level?

    // TODO: Load inital level and init the gameEnvironment
    
    gameEnvironment->Init();

    /* Main Loop whilst window is open. */
    while(!glfwWindowShouldClose(engine->getWindow()))
    {
        //inputController.processInput(window);
        gameEnvironment->GameLoop();
        graphicsController.Render();
    }

    /* Log window closed and terminate the program. */
    printf("Window Closed\n");
    engine->terminate();
    return 0;
}