#include "ObjectController.hpp"

/**
 *  Add Game Object
 */
void ObjectController::addGameObject(Object* object) {
    gameObjects.push_back(object);
}

/**
 *  Get Game Object by index.
 */
Object* ObjectController::getGameObject(int index) {
    if(index >= 0 && index <= gameObjects.size() - 1) {
        return gameObjects.at(index);
    } else {
        return nullptr;
    }
}

/**
 *  Delete Game Object
 */
void ObjectController::deleteGameObject(Object* object) {
    auto it = std::find(gameObjects.begin(), gameObjects.end(), object);
    if(it != gameObjects.end()) {
        gameObjects.erase(it);
    }
}