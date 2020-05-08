#ifndef HESTIA_INPUT_INPUT_MANAGER_H
#define HESTIA_INPUT_INPUT_MANAGER_H

#include "input/InputTypes.h"

namespace HGE {
    class InputManager {

        public:
        InputManager() = default;
        ~InputManager() = default;

        bool getKeyValue(KeyType key);
    };
}
#endif
