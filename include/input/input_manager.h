#ifndef HESTIA_INPUT_INPUT_MANAGER_H
#define HESTIA_INPUT_INPUT_MANAGER_H

#include "input/input_types.h"
#include "graphics/graphics_module.h"

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
