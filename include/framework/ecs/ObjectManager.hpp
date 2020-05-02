#ifndef HESTIA_FRAMEWORK_ECS_OBJECTMANAGER_H_
#define HESTIA_FRAMEWORK_ECS_OBJECTMANAGER_H_

#include <vector>
#include <memory>

#include "Object.hpp"
#include "ComponentManager.hpp"

namespace HGE {
    
    class ObjectManager 
    {
        private:
        std::vector<std::unique_ptr<Object>> mObjects;
        double start;

        public:
        template<class T>
        Object* CreateObject() {
            mObjects.push_back(std::unique_ptr<T>(new T()));
            mObjects.back()->onCreate();
            return mObjects.back().get();
        }

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