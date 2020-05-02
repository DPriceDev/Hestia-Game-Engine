/**
 * Copyright D. price 2020.
 */

#include <iostream>
#include <memory>

#include "framework/Engine.hpp"
#include "framework/GameEnvironment.hpp"

#include "graphics/OpenGlModule.hpp"

#include "util/Logger.hpp"

/* Function Declarations */
HGE::Engine *HGE::Engine::mEngine;
HGE::Logger HGE::Logger::mLogger;

/**
 * Main Entry Point.
 */
int main(void) 
{
    HGE::Engine* engine = HGE::Engine::getInstance();
    if(!engine->Init(std::make_unique<HGE::OpenGlModule>())) {
        return -1;
    }

    std::unique_ptr<HGE::GameEnvironment> gameEnvironment = std::make_unique<HGE::GameEnvironment>();
    gameEnvironment->Init();
    // TODO: Load inital config and get initial level?
    // TODO: Load inital level and init the gameEnvironment
    
    /* Main Loop whilst window is open. */
    while(engine->getInstance()->getGraphicsModule()->isWindowOpen())
    {
        gameEnvironment->GameLoop();
    }

    engine->terminate();
    return 0;
}