#include "framework/control/ControlSystem.hpp"

#include "framework/Engine.hpp"

namespace HGE {

    System<ControlComponent>::System(ComponentArray<ControlComponent>* componentArray) : mComponentsArray(componentArray) { 
        mInputManager = Engine::getInstance()->getInputManager();
        Logger::getInstance()->logDebug("Control System", "Created");
    }

    void System<ControlComponent>::run() {
        for(auto & component : mComponentsArray->getComponents()) {
            for( auto & [key, val] : component.mKeys ) {
                val = mInputManager->getKeyValue(key);
            }
        }
    }

}