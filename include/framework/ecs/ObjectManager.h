#ifndef HESTIA_FRAMEWORK_ECS_OBJECTMANAGER_H
#define HESTIA_FRAMEWORK_ECS_OBJECTMANAGER_H

#include <vector>
#include <memory>

#include "Object.h"

namespace HGE {
    class ObjectManager {
        std::vector<std::unique_ptr<Object>> mObjects{ };

        public:
        template<class T>
        T* CreateObject() {
            auto objectPointer = std::unique_ptr<T>(new T());
            auto ptr = objectPointer.get();
            mObjects.push_back(std::move(objectPointer));
            mObjects.back()->onCreate();
            return ptr;
        }

        template<class T>
        T* GetObject(UID id) {
            auto func = [&] (const std::unique_ptr<Object> & pObject) { 
                return pObject->getId() == id;
            };
            auto it = std::find_if(mObjects.begin(), mObjects.end(), func);
            return dynamic_cast<T*>(*it);
        }

        void DestroyObject(UID id);

        ObjectManager() : mObjects(std::vector<std::unique_ptr<Object>>()) { }
        ~ObjectManager() = default;
    };
}

#endif