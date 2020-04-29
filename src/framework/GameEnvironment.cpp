#include "GameEnvironment.hpp"

#include "../src/sample/SampleTriangleObject.hpp"

#include "Engine.hpp"

/**
 * 
 */
void GameEnvironment::Init() {
    //TODO: Replace with some sort of game instance config, load from file?

    Engine::getInstance()->getObjectManager()->CreateObject<SampleTriangleObject>();
}

/**
 * 
 */
void GameEnvironment::GameLoop() { 

    Engine::getInstance()->getObjectManager()->tick();
    Engine::getInstance()->getGraphicsModule()->startFrame();
    Engine::getInstance()->getSystemManager()->run();
    Engine::getInstance()->getGraphicsModule()->renderFrame();
}