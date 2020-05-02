#include "framework/ecs/ObjectManager.hpp"

#include <chrono>
#include <iostream>
#include <algorithm>

#include "framework/Engine.hpp"

#include "framework/ecs/Object.hpp"
#include "util/Logger.hpp"

namespace HGE {

    ObjectManager::ObjectManager() {
        mObjects = std::vector<Object*>();
        start = 0;
    }

    void ObjectManager::AddObject(Object* object) {
        Logger::getInstance()->logDebug("Object Manager", "Added to object vector array");
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
}