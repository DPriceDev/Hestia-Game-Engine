#ifndef HESTIA_FRAMEWORK_OBJECTS_OBJECTMANAGER_H_
#define HESTIA_FRAMEWORK_OBJECTS_OBJECTMANAGER_H_

#include <vector>

#include "Object.hpp"
#include "../src/framework/components/ComponentManager.hpp"

/**
 * Object Manager
 */
class ObjectManager 
{
    private:
    std::vector<Object*> mObjects;

    public:
    template<class T>
    Object* CreateObject() {
        T* object = new T();
        mObjects.push_back(object);
        object->onCreate();
        return object;
    }

    void AddObject(Object* object);
    Object* GetObject(long uid);
    void DestroyObject(long uid);

    ObjectManager() {
        mObjects = std::vector<Object*>();
    }

    ~ObjectManager() {
        // TODO: Check delete objects here?
    }
};

#endif