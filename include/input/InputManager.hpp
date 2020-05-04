#ifndef HESTIA_INPUT_INPUT_MANAGER_HPP_
#define HESTIA_INPUT_INPUT_MANAGER_HPP_

#include "input/InputTypes.hpp"

namespace HGE {
    class InputManager {

        public:
        InputManager();
        ~InputManager();

        bool getKeyValue(KeyType key);
    };
}
#endif
