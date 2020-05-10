#ifndef HESTIA_FRAMEWORK_TICK_SYSTEM_H
#define HESTIA_FRAMEWORK_TICK_SYSTEM_H

#include <functional>

#include "framework/ecs/Component.h"
#include "framework/ecs/System.h"

namespace HGE {

    /**
     * Tick Component
     */
    struct TickComponent : Component {
        std::function<void(double)> mTickFunction;

        TickComponent(UID ownerId, std::function<void(double)> tickFunction) : Component(ownerId), mTickFunction(tickFunction) { }
        ~TickComponent() = default;
    };

    /**
     * Tick System
     */
    template<>
    class System<TickComponent> : public ISystem {
        ComponentArray<TickComponent>* mTickArray;

        public:
        System(ComponentArray<TickComponent>* componentArray);
        ~System() = default;

        void run() override;
    };
}

#endif