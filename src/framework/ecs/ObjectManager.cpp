#include "ObjectManager.hpp"

#include <chrono>

#include "Object.hpp"
#include "../src/util/Logger.hpp"

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

auto start = std::chrono::high_resolution_clock::now();

void ObjectManager::tick() {

    auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count();

    for(auto & object : mObjects) {
        object->tick(deltaTime);
    }

    start = std::chrono::high_resolution_clock::now();

}