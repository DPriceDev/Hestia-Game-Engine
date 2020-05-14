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

        explicit TickComponent(UID ownerId) : IComponent(ownerId) { }

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