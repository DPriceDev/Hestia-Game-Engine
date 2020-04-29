#include "ObjectManager.hpp"

#include <chrono>
#include <iostream>

#include "../src/framework/Engine.hpp"

#include "Object.hpp"
#include "../src/util/Logger.hpp"

ObjectManager::ObjectManager() {
    mObjects = std::vector<Object*>();
    start = 0;
}

void ObjectManager::AddObject(Object* object) {
    LogDebug("Added to object controller stack");
    mObjects.push_back(object);
}

Object* ObjectManager::GetObject(long uid) {
    auto it = std::find_if(mObjects.begin(), mObjects.end(), [&uid] (const Object* pObject) { 
        return pObject->getId() == uid;
        });

        return *it;
}

void ObjectManager::DestroyObject(long uid) {
        auto it = std::find_if(mObjects.begin(), mObjects.end(), [&uid] (const Object* pObject) { 
        return pObject->getId() == uid;
        });
        mObjects.erase(it);
}

void ObjectManager::tick() {
    auto deltaTime = Engine::getInstance()->getGraphicsModule()->getGameTime() - start;

    for(auto & object : mObjects) {
        object->tick(deltaTime);
    }

    start = Engine::getInstance()->getGraphicsModule()->getGameTime();
}