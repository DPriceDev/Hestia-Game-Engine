#ifndef HESTIA_FRAMEWORK_WORLD_POSITION_H
#define HESTIA_FRAMEWORK_WORLD_POSITION_H

#include "framework/ecs/Component.h"
#include "framework/ecs/System.h"
#include "framework/ecs/ComponentManager.h"

#include "maths/MathsTypes.h"

#include "util/Logger.h"

namespace HGE {

    /**
     * World Position Component
     */
    struct WorldPositionComponent : public Component {
        Transform2f mTransform;

        WorldPositionComponent(UID ownerId) : Component(ownerId), mTransform(Transform2f()) { }
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
            Logger::instance()->logDebug("World Position System", "Created!");
        }
        ~System() = default;

        void run() override { }
    };
}

#endif /* HESTIA_FRAMEWORK_WORLD_POSITION_H */