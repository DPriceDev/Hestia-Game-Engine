#ifndef HESTIA_FRAMEWORK_OBJECTS_OBJECTMANAGER_H_
#define HESTIA_FRAMEWORK_OBJECTS_OBJECTMANAGER_H_

#include <vector>

#include "Object.hpp"

class Object;

/**
 * Object Manager
 */
class ObjectManager 
{
    private:
    std::vector<Object*> mObjects;

    public:
    void AddObject(Object* object);
    Object* GetObject(long uid);
    void DestroyObject(long uid);
};

#endif