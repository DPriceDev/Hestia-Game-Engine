#ifndef HESTIA_FRAMEWORK_TICK_SYSTEM_H
#define HESTIA_FRAMEWORK_TICK_SYSTEM_H

#include <functional>
#include <utility>

#include "framework/ecs/Component.h"
#include "framework/ecs/System.h"

namespace HGE {

    /**
     * Tick Component
     */
    struct TickComponent : Component {
        std::function<void(double)> mTickFunction;

        TickComponent(UID ownerId, std::function<void(double)> tickFunction) : Component(ownerId), mTickFunction(std::move(tickFunction)) { }
        ~TickComponent() override = default;
    };

    /**
     * Tick System
     */
    template<>
    class System<TickComponent> : public ISystem {
        ComponentArray<TickComponent>* mTickArray;

        public:
        explicit System(ComponentArray<TickComponent>* componentArray);
        ~System() override = default;

        void run() override;
    };
}

#endif