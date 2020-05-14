//
// Created by David Price on 14/05/2020.
//

#ifndef HESTIA_ROGUELIKE_ECS_FACADE_H
#define HESTIA_ROGUELIKE_ECS_FACADE_H

#include "ObjectManager.h"
#include "ComponentManager.h"

namespace HGE {

    class EcsFacade {
        friend class Engine;
        friend class ObjectManager;
        friend class ComponentManager;
        ObjectManager *mObjectManager;
        ComponentManager *mComponentManager;

    public:
        template<typename obj>
        obj* createObject() {
            return mObjectManager->createObject<obj>();
        }

        template<typename obj>
        std::optional<obj*> getObjectById(const UID &id) const {
            return mObjectManager->getObjectById<obj>(id);
        }

        void destroyObject(const UID &id) const {
            mObjectManager->destroyObject(id);
        }

        template<typename Comp, typename ... Args>
        Comp* createComponent(Args... args) {
            return mComponentManager->createComponent<Comp>(std::forward<Args>(args)...);
        }

        template<typename Comp>
        void destroyComponent(UID objectId) {
            mComponentManager->deleteComponentById<Comp>(objectId);
        }

        template<typename Comp>
        void destroyComponent(Comp* component) {
            mComponentManager->deleteComponentByPtr<Comp>(component);
        }
    };
}
#endif //HESTIA_ROGUELIKE_ECS_FACADE_H
