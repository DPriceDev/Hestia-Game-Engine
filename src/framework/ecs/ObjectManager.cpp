#include "framework/ecs/ObjectManager.hpp"

#include <chrono>
#include <iostream>
#include <algorithm>

#include "framework/Engine.hpp"

#include "framework/ecs/Object.hpp"
#include "util/Logger.hpp"

namespace HGE {

    ObjectManager::ObjectManager() {
        mObjects = std::vector<std::unique_ptr<Object>>();
        start = 0;
    }

    Object* ObjectManager::GetObject(int uid) {
        auto it = std::find_if(mObjects.begin(), mObjects.end(), [&uid] (const std::unique_ptr<Object> & pObject) { 
            return pObject->getId() == uid;
            });

            return it->get();
    }

    void ObjectManager::DestroyObject(int uid) {
            auto it = std::find_if(mObjects.begin(), mObjects.end(), [&uid] (const std::unique_ptr<Object> & pObject) { 
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