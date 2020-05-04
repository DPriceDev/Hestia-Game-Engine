#ifndef HESTIA_FRAMEWORK_INPUT_COMPONENT_HPP_
#define HESTIA_FRAMEWORK_INPUT_COMPONENT_HPP_

#include <vector>
#include <map>
#include <utility>

#include "framework/ecs/Component.hpp"
#include "input/InputTypes.hpp"

namespace HGE {

    struct InputComponent : Component {

        std::map<KeyType, bool> mKeys;

        InputComponent() : Component("Input") {
            mKeys = std::map<KeyType, bool>();
        }
        ~InputComponent() { }

        void addKey(KeyType key);
        void removeKey(KeyType key);
        bool getKeyValue(KeyType key);
        void registerSystem() override;
    };
}

#endif