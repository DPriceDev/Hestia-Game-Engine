//
// Created by David Price on 04/03/2021.
//

#ifndef HESTIA_FRAMEWORK_ECS_INTERACTOR_COMPONENT_ARRAY_INTERACTOR_H
#define HESTIA_FRAMEWORK_ECS_INTERACTOR_COMPONENT_ARRAY_INTERACTOR_H

#include <optional>

#include "context.h"
#include "framework/ecs/component_array_container.h"

namespace HGE {
    /* */
    template<component Comp>
    ComponentArray<Comp>* getOrCreateComponentArray(const Context* context) {
        auto array = context->mComponentManager->getComponentArray<Comp>();
        if(array.has_value()) {
            return array.value();
        } else {
            return context->mComponentManager->createComponentArray<Comp>();
        }
    }
}

#endif //HESTIA_FRAMEWORK_ECS_INTERACTOR_COMPONENT_ARRAY_INTERACTOR_H
