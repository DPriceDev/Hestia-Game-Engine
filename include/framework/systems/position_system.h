#ifndef HESTIA_FRAMEWORK_WORLD_POSITION_H
#define HESTIA_FRAMEWORK_WORLD_POSITION_H

#include "framework/ecs/component.h"
#include "framework/ecs/component_manager.h"
#include "framework/ecs/system.h"

#include "maths/maths_types.h"

#include "util/logger.h"

namespace HGE {

    /**
     * World Position IComponent
     */
    struct PositionComponent : public IComponent {
        Transform2f mTransform;

        const float &getX() { return mTransform.mLocalPosition.x; }
        const float &getY() { return mTransform.mLocalPosition.y; }
        const void setX(const float &value) { mTransform.mLocalPosition.x = value; }
        const void setY(const float &value) { mTransform.mLocalPosition.y = value; }

        explicit PositionComponent(UID ownerId) : IComponent(ownerId), mTransform(Transform2f()) {}
        ~PositionComponent() override = default;
    };

    /**
     * World Position System
     */
    template<>
    class System<PositionComponent> : public ISystem {

        ComponentArray<PositionComponent> *mComponentsArray;

    public:
        explicit System(ComponentArray<PositionComponent> *componentArray) : mComponentsArray(componentArray) {
            Logger::instance()->logDebug("World Position System", "Created!");
        }
        ~System() override = default;

        void run(const double &deltaTime) override {}
    };
}// namespace HGE

#endif /* HESTIA_FRAMEWORK_WORLD_POSITION_H */