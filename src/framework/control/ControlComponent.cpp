#include "framework/control/ControlComponent.hpp"

using namespace HGE;

void ControlComponent::addKey(KeyType key) {
    mKeys[key] = false;
}

void ControlComponent::removeKey(KeyType key) {
    auto it = mKeys.find(key);
    mKeys.erase(it);
}

bool ControlComponent::getKeyValue(KeyType key) {
    auto it = mKeys.find(key);
    if(it != mKeys.end()) {
        return mKeys[key];
    } else {
        return false;
    }
}