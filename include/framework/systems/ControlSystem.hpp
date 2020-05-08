#ifndef HESTIA_FRAMEWORK_CONTROL_SYSTEM_HPP_
#define HESTIA_FRAMEWORK_CONTROL_SYSTEM_HPP_

#include <map>

#include "framework/ecs/ecs.h"

#include "input/InputManager.hpp"
#include "input/InputTypes.hpp"

#include "util/Logger.hpp"

namespace HGE {

    /**
     * Control Component
     */
    struct ControlComponent : public Component {

        std::map<KeyType, bool> mKeys;

        void addKey(KeyType key);
        void removeKey(KeyType key);
        bool getKeyValue(KeyType key);

        ControlComponent(UID ownerId) : Component(ownerId), mKeys(std::map<KeyType, bool>()) { }
        ~ControlComponent() { }
    };

    /**
     * Control System
     */
    template <>
    class System<ControlComponent> : public ISystem {

        ComponentArray<ControlComponent>* mComponentsArray;
        InputManager* mInputManager;

        public:
        System(ComponentArray<ControlComponent>* componentArray);
        ~System() = default;

        void run() override;
    };
}

#endif