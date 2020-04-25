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
    ComponentManager* mComponentManager;

    public:
    void AddObject(Object* object);
    Object* GetObject(long uid);
    void DestroyObject(long uid);

    ObjectManager(ComponentManager* componentManager) : mComponentManager(componentManager) {
        mObjects = std::vector<Object*>();
    }

    ~ObjectManager() {
        delete mComponentManager;
        // TODO: Check delete objects here?
    }
};

#endif