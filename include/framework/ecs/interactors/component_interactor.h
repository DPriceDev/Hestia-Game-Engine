//
// Created by David Price on 04/03/2021.
//

#ifndef HESTIA_FRAMEWORK_ECS_INTERACTOR_COMPONENT_INTERACTOR_H
#define HESTIA_FRAMEWORK_ECS_INTERACTOR_COMPONENT_INTERACTOR_H

#include <optional>
#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "context.h"
#include "framework/ecs/interactors/component_array_interactor.h"
#include "framework/ecs/component_manager.h"
#include "framework/ecs/system_manager.h"

namespace HGE {
    namespace ECS {

        /* */
        template<typename Comp, typename... Args>
        Comp *createComponent(Context* context, Args... args) {
            auto array = context->mComponentManager->getComponentArray<Comp>();
            ComponentArray<Comp> *pArray;

            if (array.has_value()) {
                pArray = array.value();
            } else {
                pArray = context->mComponentManager->createComponentArray<Comp>();
                context->mSystemManager->createSystem<Comp>(context, pArray);
            }
            return pArray->createComponent(std::forward<Args>(args)...);
        }

        /* */
        template<typename Comp>
        void destroyComponent(const Context* context, const UID objectId) {
            auto array = context->mComponentManager->getComponentArray<Comp>();
            if(array.has_value()) {
                array.value()->deleteComponentWithOwner(objectId);
            }
        }

        /* */
        template<typename Comp>
        void destroyComponent(const Context* context, const Comp *component) {
            auto array = context->mComponentManager->getComponentArray<Comp>();
            if(array.has_value()) {
                array.value()->deleteComponentWithOwner(component->getOwnerUID());
            }
            //context->mComponentManager->deleteComponentByPtr<Comp>(component);
        }
    }
}

#endif
