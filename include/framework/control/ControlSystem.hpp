#ifndef HESTIA_FRAMEWORK_CONTROL_SYSTEM_HPP_
#define HESTIA_FRAMEWORK_CONTROL_SYSTEM_HPP_

#include "framework/ecs/System.hpp"
#include "framework/ecs/ComponentManager.hpp"
#include "input/InputManager.hpp"
#include "ControlComponent.hpp"

#include "util/Logger.hpp"

namespace HGE {

    template <>
    class System<ControlComponent> : public ISystem {

        ComponentArray<ControlComponent>* mComponentsArray;
        InputManager* mInputManager;

        public:
        System(ComponentArray<ControlComponent>* componentArray);
        ~System() = default;

        void run() override;
    };
}

#endif