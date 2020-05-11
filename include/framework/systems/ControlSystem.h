#ifndef HESTIA_FRAMEWORK_CONTROL_SYSTEM_H
#define HESTIA_FRAMEWORK_CONTROL_SYSTEM_H

#include <map>

#include "framework/ecs/Component.h"
#include "framework/ecs/System.h"

#include "input/InputManager.h"
#include "input/InputTypes.h"

#include "util/Logger.h"

namespace HGE {

    /**
     * Control Component
     */
    struct ControlComponent : public Component {

        std::map<KeyType, bool> mKeys;

        void addKey(KeyType key);
        void removeKey(KeyType key);
        bool getKeyValue(KeyType key);

        explicit ControlComponent(UID ownerId) : Component(ownerId), mKeys(std::map<KeyType, bool>()) { }
        ~ControlComponent() override = default;
    };

    /**
     * Control System
     */
    template <>
    class System<ControlComponent> : public ISystem {

        ComponentArray<ControlComponent>* mComponentsArray;
        InputManager* mInputManager;

        public:
        explicit System(ComponentArray<ControlComponent>* componentArray);
        ~System() override = default;

        void run() override;
    };
}

#endif