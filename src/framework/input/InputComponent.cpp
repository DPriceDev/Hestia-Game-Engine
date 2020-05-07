#include "framework/input/InputComponent.hpp"
#include "framework/Engine.hpp"
#include "framework/input/InputSystem.hpp"

using namespace HGE;

void InputComponent::registerSystem() {
    //Engine::getInstance()->getSystemManager()->createSystem<InputSystem>();
}

void InputComponent::addKey(KeyType key) {
    mKeys[key] = false;
}

void InputComponent::removeKey(KeyType key) {
    auto it = mKeys.find(key);
    mKeys.erase(it);
}

bool InputComponent::getKeyValue(KeyType key) {
    auto it = mKeys.find(key);
    if(it != mKeys.end()) {
        return mKeys[key];
    } else {
        return false;
    }
}