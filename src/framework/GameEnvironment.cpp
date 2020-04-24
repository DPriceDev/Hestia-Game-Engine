#include "GameEnvironment.hpp"

/**
 * 
 */
void GameEnvironment::Init() {
    //TODO: Replace with some sort of game instance config, load from file?
    mObjectController->AddGameObject(new SampleTriangleObject());
}

/**
 * 
 */
void GameEnvironment::GameLoop() {
    for(auto & object : mObjects) {
        object->tick();
    }
}