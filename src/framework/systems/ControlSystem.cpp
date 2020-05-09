#include "framework/systems/ControlSystem.h"
#include "framework/Engine.h"

namespace HGE {

    /**
     * Control Component Methods
     */    
    void ControlComponent::addKey(KeyType key) {
        mKeys[key] = false;
    }

    void ControlComponent::removeKey(KeyType key) {
        auto it = mKeys.find(key);
        mKeys.erase(it);
    }

    bool ControlComponent::getKeyValue(KeyType key) {
        auto it = mKeys.find(key);
        if(it != mKeys.end()) {
            return mKeys[key];
        } else {
            return false;
        }
    }

    /**
     * Control System Methods
     */    
    System<ControlComponent>::System(ComponentArray<ControlComponent>* componentArray) : mComponentsArray(componentArray) { 
        mInputManager = Engine::instance()->inputManager();
        Logger::getInstance()->logDebug("Control System", "Created");
    }

    void System<ControlComponent>::run() {
        for(auto & component : mComponentsArray->getComponents()) {
            for( auto & [key, val] : component->mKeys ) {
                val = mInputManager->getKeyValue(key);
            }
        }
    }

}