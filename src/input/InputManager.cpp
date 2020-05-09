#include "input/InputManager.h"

#include "framework/Engine.h"

namespace HGE {
    bool InputManager::getKeyValue(KeyType key) {
        return Engine::instance()->graphicsModule()->getKeyValue(key);
    }
}