#include "framework/systems/tick_system.h"
#include "engine.h"

namespace HGE {

    /**
     * Tick System Methods
     */
    System<TickComponent>::System(ComponentArray<TickComponent> *componentArray) : mTickArray(componentArray) {}

    void System<TickComponent>::run(const double &deltaTime) {
        for (auto &component : mTickArray->getComponents()) {
            component->mTickFunction(deltaTime);
        }
    }
}// namespace HGE