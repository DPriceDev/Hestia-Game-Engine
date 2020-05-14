#ifndef HESTIA_INPUT_INPUT_MANAGER_H
#define HESTIA_INPUT_INPUT_MANAGER_H

#include "input/InputTypes.h"
#include "graphics/GraphicsModule.h"

namespace HGE {
    class InputManager {
        GraphicsModule* mGraphicsModule;

    public:
        explicit InputManager(GraphicsModule* graphicsModule) : mGraphicsModule(graphicsModule) { }
        ~InputManager() = default;

        [[nodiscard]] bool getKeyValue(const KeyType key) const {
            return mGraphicsModule->getKeyValue(key);
        }
    };
}
#endif
