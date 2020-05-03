#ifndef HESTIA_FRAMEWORK_INPUT_COMPONENT_HPP_
#define HESTIA_FRAMEWORK_INPUT_COMPONENT_HPP_

#include <vector>
#include <utility>

#include "framework/ecs/Component.hpp"
#include "input/InputTypes.hpp"

namespace HGE {

    struct InputComponent : Component {

        std::vector<std::pair<KeyType, bool>> mKeys;

        InputComponent() : Component("Input") {
            mKeys = std::vector<std::pair<KeyType, bool>>();
        }
        ~InputComponent() { }

        void registerSystem() override;
    };
}

#endif