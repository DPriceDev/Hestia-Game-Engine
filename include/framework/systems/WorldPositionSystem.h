#ifndef HESTIA_FRAMEWORK_WORLD_POSITION_H
#define HESTIA_FRAMEWORK_WORLD_POSITION_H

#include "framework/ecs/IComponent.h"
#include "framework/ecs/System.h"
#include "framework/ecs/ComponentManager.h"

#include "maths/MathsTypes.h"

#include "util/Logger.h"

namespace HGE {

    /**
     * World Position IComponent
     */
    struct WorldPositionComponent : public IComponent {
        Transform2f mTransform;

        const float& getX() { return mTransform.mLocalPosition.x; }
        const float& getY() { return mTransform.mLocalPosition.y; }
        const void setX(const float& value) { mTransform.mLocalPosition.x = value; }
        const void setY(const float& value) { mTransform.mLocalPosition.y = value; }

        explicit WorldPositionComponent(UID ownerId) : IComponent(ownerId), mTransform(Transform2f()) { }
        ~WorldPositionComponent() override = default;
    };

    /**
     * World Position System
     */
    template <>
    class System<WorldPositionComponent> : public ISystem {

        ComponentArray<WorldPositionComponent>* mComponentsArray;

        public:
        explicit System(ComponentArray<WorldPositionComponent>* componentArray) : mComponentsArray(componentArray) {
            Logger::instance()->logDebug("World Position System", "Created!");
        }
        ~System() override = default;

        void run() override { }
    };
}

#endif /* HESTIA_FRAMEWORK_WORLD_POSITION_H */