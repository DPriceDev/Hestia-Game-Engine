#ifndef HESTIA_FRAMEWORK_CONTROL_SYSTEM_H
#define HESTIA_FRAMEWORK_CONTROL_SYSTEM_H

#include <context.h>
#include <map>

#include "framework/ecs/component.h"
#include "framework/ecs/component_array.h"
#include "framework/ecs/system.h"

#include "input/input_manager.h"
#include "input/input_types.h"

#include "util/logger.h"

namespace HGE {

    /**
     * Control IComponent
     */
    struct ControlComponent : public IComponent {

        std::map<KeyType, bool> mKeys;

        void addKey(KeyType key);
        void removeKey(KeyType key);
        bool getKeyValue(KeyType key);

        explicit ControlComponent(UID ownerId) : IComponent(ownerId), mKeys(std::map<KeyType, bool>()) {}
        ~ControlComponent() override = default;
    };

    /**
     * Control System
     */
    template<>
    class System<ControlComponent> : public ISystem {
        Context* mContext;
        ComponentArray<ControlComponent> *mComponentsArray;

    public:
        explicit System(Context* context, ComponentArray<ControlComponent> *componentArray);
        ~System() override = default;

        void run(const double &deltaTime) override;
    };
}// namespace HGE

#endif