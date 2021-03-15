#include "game/systems/tick_system.h"
#include "engine.h"

namespace HGE {

    /**
     * Tick System Methods
     */
    System<TickComponent>::System(Context* /*context*/, ComponentArray<TickComponent> *componentArray) : mTickArray(componentArray) {}

    void System<TickComponent>::run(const double &deltaTime) {
        for (auto &component : mTickArray->getComponents()) {
            component->mTickFunction(deltaTime);
        }
    }
}// namespace HGE