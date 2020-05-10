#include "framework/systems/TickSystem.h"
#include "framework/Engine.h"

namespace HGE {

    /**
     * Tick System Methods
     */   
    System<TickComponent>::System(ComponentArray<TickComponent>* componentArray) : mTickArray(componentArray) { }

    void System<TickComponent>::run() {
        for(auto & component : mTickArray->getComponents()) { 
            component->mTickFunction(Engine::tickTime());
        }
    }
}