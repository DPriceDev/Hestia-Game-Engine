#ifndef HESTIA_FRAMEWORK_CONTROL_COMPONENT_HPP_
#define HESTIA_FRAMEWORK_CONTROL_COMPONENT_HPP_

#include <vector>
#include <map>
#include <utility>

#include "framework/ecs/Component.hpp"
#include "input/InputTypes.hpp"

namespace HGE {
    struct ControlComponent : public Component {

        std::map<KeyType, bool> mKeys;

        void addKey(KeyType key);
        void removeKey(KeyType key);
        bool getKeyValue(KeyType key);

        ControlComponent(UID ownerId) : Component(ownerId), mKeys(std::map<KeyType, bool>()) { }
        ~ControlComponent() { }
    };
}

#endif