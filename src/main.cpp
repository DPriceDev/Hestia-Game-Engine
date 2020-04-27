/**
 * Copyright D. price 2020.
 */

#include <iostream>

#include "framework/Engine.hpp"
#include "framework/GameEnvironment.hpp"

#include "../src/graphics/OpenGlModule.hpp"

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

    Engine* engine = Engine::getInstance();

    if(!engine->Init(new OpenGlModule())) {
        return -1;
    }

    GameEnvironment* gameEnvironment = new GameEnvironment();

    // TODO: Load inital config and get initial level?

    // TODO: Load inital level and init the gameEnvironment
    
    gameEnvironment->Init();

    /* Main Loop whilst window is open. */
    while(engine->getInstance()->getGraphicsModule()->isWindowOpen())
    {
        //inputController.processInput(window);
        gameEnvironment->GameLoop();
        //graphicsController.Render();
    }

    /* Log window closed and terminate the program. */
    printf("Window Closed\n");
    engine->terminate();
    return 0;
}