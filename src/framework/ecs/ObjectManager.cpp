#include "framework/ecs/ObjectManager.h"

#include <algorithm>

#include "framework/ecs/Object.h"

namespace HGE {

    void ObjectManager::DestroyObject(UID id) {
            auto it = std::find_if(mObjects.begin(), mObjects.end(), [&] (const std::unique_ptr<Object> & pObject) { 
            return pObject->getId() == id;
            });
            mObjects.erase(it);
    }
}