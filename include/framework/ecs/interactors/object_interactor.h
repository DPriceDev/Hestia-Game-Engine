//
// Created by David Price on 04/03/2021.
//

#ifndef HESTIA_FRAMEWORK_ECS_INTERACTOR_OBJECT_INTERACTOR_H
#define HESTIA_FRAMEWORK_ECS_INTERACTOR_OBJECT_INTERACTOR_H

#include <optional>

#include "framework/ecs/object_manager.h"
#include "context.h"

namespace HGE {
    namespace ECS {

        /* */
        template<ObjectConcept obj>
        obj *createObject(const Context* context) {
            return context->mObjectManager->createObject<obj>();
        }

        /* */
        template<ObjectConcept obj>
        std::optional<obj *> getObjectById(const Context* context, const UID &id) {
            return context->mObjectManager->getObjectById<obj>(id);
        }

        /* */
//        void destroyObject(Context* context, UID &id) {
//            context->mObjectManager->destroyObject(id);
//        }
    }
}

#endif
