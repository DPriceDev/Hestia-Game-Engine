#ifndef HESTIA_FRAMEWORK_WORLD_POSITION_H
#define HESTIA_FRAMEWORK_WORLD_POSITION_H

#include "framework/ecs/ecs.h"
#include "framework/ecs/ComponentManager.h"

#include "util/Logger.h"

namespace HGE {

    /**
     * World Position Component
     */
    struct WorldPositionComponent : public Component {
        WorldPositionComponent(UID ownerId) : Component(ownerId) { }
        ~WorldPositionComponent() = default;
    };

    /**
     * World Position System
     */
    template <>
    class System<WorldPositionComponent> : public ISystem {

        ComponentArray<WorldPositionComponent>* mComponentsArray;

        public:
        System(ComponentArray<WorldPositionComponent>* componentArray) : mComponentsArray(componentArray) {
            Logger::getInstance()->logDebug("World Position System", "Created!");
        }
        ~System() = default;

        void run() override { }
    };
}

#endif /* HESTIA_FRAMEWORK_WORLD_POSITION_H */