#ifndef HESTIA_FRAMEWORK_TICK_SYSTEM_H
#define HESTIA_FRAMEWORK_TICK_SYSTEM_H

#include <functional>
#include <utility>

#include "framework/ecs/IComponent.h"
#include "framework/ecs/System.h"

namespace HGE {

    /**
     * Tick IComponent
     */
    struct TickComponent : IComponent {
        std::function<void(double)> mTickFunction;

        TickComponent(UID ownerId, std::function<void(double)> tickFunction)
                        : IComponent(ownerId), mTickFunction(std::move(tickFunction)) { }

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

        void run(const double& deltaTime) override;
    };
}

#endif