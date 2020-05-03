#ifndef HESTIA_FRAMEWORK_INPUT_SYSTEM_HPP_
#define HESTIA_FRAMEWORK_INPUT_SYSTEM_HPP_

#include "framework/ecs/System.hpp"

#include "framework/ecs/Component.hpp"

namespace HGE {

    class InputSystem : public System {
        
        private:
        std::vector<Component*>* mComponents;

        public:
        InputSystem();
        ~InputSystem();

        void run() override;
    };
}

#endif