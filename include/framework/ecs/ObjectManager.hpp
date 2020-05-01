#ifndef HESTIA_FRAMEWORK_ECS_OBJECTMANAGER_H_
#define HESTIA_FRAMEWORK_ECS_OBJECTMANAGER_H_

#include <vector>

#include "Object.hpp"
#include "ComponentManager.hpp"

namespace HGE {
    
    class ObjectManager 
    {
        private:
        std::vector<Object*> mObjects;
        double start;

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

        void tick();

        ObjectManager();

        ~ObjectManager() {
            // TODO: Check delete objects here?
        }
    };
}

#endif