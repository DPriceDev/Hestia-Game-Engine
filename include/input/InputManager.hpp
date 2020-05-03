#ifndef HESTIA_INPUT_INPUT_MANAGER_HPP_
#define HESTIA_INPUT_INPUT_MANAGER_HPP_

#include "input/InputTypes.hpp"

namespace {

    class InputManager {

        public:
        InputManager();
        ~InputManager();

        void registerKeyCallback();
        void deregisterKeyCallback();
    };
}
#endif
