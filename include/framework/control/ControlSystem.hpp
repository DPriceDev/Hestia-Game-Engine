#ifndef HESTIA_FRAMEWORK_CONTROL_SYSTEM_HPP_
#define HESTIA_FRAMEWORK_CONTROL_SYSTEM_HPP_

#include "framework/ecs/System.hpp"
#include "ControlComponent.hpp"

#include "util/Logger.hpp"

namespace HGE {

    template <>
    class System<ControlComponent> : public ISystem {

        public:
        System() { 
            Logger::getInstance()->logDebug("Control System", "Created");
        }
        ~System() { }

        void run() override { }
    };
}

#endif