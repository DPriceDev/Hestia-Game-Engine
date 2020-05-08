#ifndef HESTIA_FRAMEWORK_WORLD_POSITION_H
#define HESTIA_FRAMEWORK_WORLD_POSITION_H

#include "framework/ecs/ComponentManager.hpp"
#include "framework/ecs/Component.hpp"
#include "framework/ecs/System.hpp"

#include "util/Logger.hpp"

namespace HGE {

    struct WorldPositionComponent : public Component {

        WorldPositionComponent(UID ownerId) : Component(ownerId) { }
        ~WorldPositionComponent() = default;

    };

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