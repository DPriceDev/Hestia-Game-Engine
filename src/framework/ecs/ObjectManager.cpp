#include "framework/ecs/ObjectManager.h"

#include <chrono>
#include <iostream>
#include <algorithm>

#include "framework/Engine.h"

#include "framework/ecs/Object.h"
#include "util/Logger.h"

namespace HGE {

    void ObjectManager::DestroyObject(UID id) {
            auto it = std::find_if(mObjects.begin(), mObjects.end(), [&] (const std::unique_ptr<Object> & pObject) { 
            return pObject->getId() == id;
            });
            mObjects.erase(it);
    }
}