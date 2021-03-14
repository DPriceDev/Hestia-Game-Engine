#include "game/systems/control_system.h"
#include "engine.h"

namespace HGE {

    /**
     * Control IComponent Methods
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
        if (it != mKeys.end()) {
            return mKeys[key];
        } else {
            return false;
        }
    }

    /**
     * Control System Methods
     */
    System<ControlComponent>::System(Context* context, ComponentArray<ControlComponent> *componentArray)
        : mContext(context), mComponentsArray(componentArray) {
        Logger::instance()->logDebug("Control System", "Created");
    }

    void System<ControlComponent>::run(const double & /*deltaTime*/) {
        for (auto &components : mComponentsArray->getComponents()) {
            for (auto &[key, val] : components->mKeys) {
                val = mContext->mInputManager->getKeyValue(key);
            }
        }
    }

}// namespace HGE