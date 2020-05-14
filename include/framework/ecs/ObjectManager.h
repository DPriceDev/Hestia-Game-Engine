#ifndef HESTIA_FRAMEWORK_ECS_OBJECT_MANAGER_H
#define HESTIA_FRAMEWORK_ECS_OBJECT_MANAGER_H

#include <vector>
#include <memory>

#include "Object.h"
#include "ComponentManager.h"

namespace HGE {

    class ObjectManager {
        ComponentManager* mComponentManager;
        std::vector<std::unique_ptr<IObject>> mObjects;

    public:
        template<class T>
        T* CreateObject() {
            auto objectPointer = std::make_unique<T>();
            auto ptr = objectPointer.get();
            mObjects.push_back(std::move(objectPointer));
            mObjects.back()->onCreate();
            return ptr;
        }

        template<class Obj>
        [[maybe_unused]]
        std::optional<Obj*> getObjectById(const UID id) const {
            constexpr auto func = [id] (const std::unique_ptr<IObject> & pObject) {
                return pObject->getId() == id;
            };
            auto it = std::find_if(mObjects.begin(), mObjects.end(), func);

            if(it != mObjects.end()) {
                return dynamic_cast<Obj*>(*it);
            } else {
                return std::nullopt;
            }
        }

        [[maybe_unused]]
        void DestroyObject(const UID id) {
            auto func = [id] (const std::unique_ptr<IObject> & pObject) {
                return pObject->getId() == id;
            };

            const auto it = std::find_if(mObjects.begin(), mObjects.end(), func);
            mObjects.erase(it);
        }

        explicit ObjectManager(ComponentManager* componentManager)
                             : mObjects(std::vector<std::unique_ptr<IObject>>()),
                               mComponentManager(componentManager) { }
        ~ObjectManager() = default;
    };
}

#endif