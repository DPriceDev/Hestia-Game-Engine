#include "input/InputManager.hpp"

#include "framework/Engine.hpp"

using namespace HGE;

InputManager::InputManager() {

}

InputManager::~InputManager() {
    
}

bool InputManager::getKeyValue(KeyType key) {
    return Engine::getInstance()->getGraphicsModule()->getKeyValue(key);
}