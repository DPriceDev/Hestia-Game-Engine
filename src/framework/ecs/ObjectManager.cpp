#include "framework/ecs/ObjectManager.h"

#include <chrono>
#include <iostream>
#include <algorithm>

#include "framework/Engine.h"

#include "framework/ecs/Object.h"
#include "util/Logger.h"

namespace HGE {

    ObjectManager::ObjectManager() {
        mObjects = std::vector<std::unique_ptr<Object>>();
        start = 0;
    }

    void ObjectManager::DestroyObject(UID id) {
            auto it = std::find_if(mObjects.begin(), mObjects.end(), [&] (const std::unique_ptr<Object> & pObject) { 
            return pObject->getId() == id;
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
}