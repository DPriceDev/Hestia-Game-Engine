#include "input/InputManager.h"

#include "framework/Engine.h"

namespace HGE {
    bool InputManager::getKeyValue(KeyType key) {
        return Engine::getInstance()->getGraphicsModule()->getKeyValue(key);
    }
}