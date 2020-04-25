#include "GameEnvironment.hpp"

#include "../src/sample/SampleTriangleObject.hpp"

#include "Engine.hpp"

/**
 * 
 */
void GameEnvironment::Init() {
    //TODO: Replace with some sort of game instance config, load from file?

    SampleTriangleObject* object = new SampleTriangleObject();

    Engine::getInstance()->getObjectManager()->AddObject(object);
}

/**
 * 
 */
void GameEnvironment::GameLoop() { }