#include "framework/ecs/ObjectManager.h"

#include <algorithm>

#include "framework/ecs/Object.h"

namespace HGE {

    void ObjectManager::DestroyObject(const UID id) {
        auto func = [id] (const std::unique_ptr<Object> & pObject) {
            return pObject->getId() == id;
        };

        const auto it = std::find_if(mObjects.begin(), mObjects.end(), func);
        mObjects.erase(it);
    }
}