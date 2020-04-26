#include "ObjectManager.hpp"
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