#ifndef HESTIA_FRAMEWORK_TICK_SYSTEM_H
#define HESTIA_FRAMEWORK_TICK_SYSTEM_H

#include <context.h>
#include <functional>
#include <utility>

#include "framework/ecs/component_array.h"
#include "framework/ecs/system.h"

namespace HGE {

    /**
     * Tick IComponent
     */
    struct TickComponent : IComponent {
        std::function<void(double)> mTickFunction;

        explicit TickComponent(UID ownerId) : IComponent(ownerId) {}

        ~TickComponent() override = default;
    };

    /**
     * Tick System
     */
    template<>
    class System<TickComponent> : public ISystem {
        Context* mContext;
        ComponentArray<TickComponent> *mTickArray;

    public:
        explicit System(Context* context, ComponentArray<TickComponent> *componentArray);
        ~System() override = default;

        void run(const double &deltaTime) override;
    };
}// namespace HGE

#endif