//
// Created by David Price on 14/05/2020.
//

#ifndef HESTIA_ROGUELIKE_ECS_FACADE_H
#define HESTIA_ROGUELIKE_ECS_FACADE_H

#include <optional>

#include "context.h"
#include "framework/ecs/object_manager.h"
#include "framework/ecs/component_manager.h"

namespace HGE {
    using UID = int;

    class EcsFacade {
        Context *mContext;

    public:
        EcsFacade(Context* context) : mContext(context) { }

        template<typename obj>
        obj *createObject() {
            return mContext->mObjectManager->createObject<obj>();
        }

        template<typename obj>
        std::optional<obj *> getObjectById(const UID &id) const {
            return mContext->mObjectManager->getObjectById<obj>(id);
        }

        void destroyObject(const UID &id) const {
            mContext->mObjectManager->destroyObject(id);
        }

        template<typename Comp, typename... Args>
        Comp *createComponent(Args... args) {
            return mContext->mComponentManager->createComponent<Comp>(std::forward<Args>(args)...);
        }

        template<typename Comp>
        void destroyComponent(UID objectId) {
            mContext->mComponentManager->deleteComponentById<Comp>(objectId);
        }

        template<typename Comp>
        void destroyComponent(Comp *component) {
            mContext->mComponentManager->deleteComponentByPtr<Comp>(component);
        }
    };
}// namespace HGE
#endif//HESTIA_ROGUELIKE_ECS_FACADE_H
