#ifndef HESTIA_FRAMEWORK_WORLD_POSITION_H
#define HESTIA_FRAMEWORK_WORLD_POSITION_H

#include "framework/ecs/component.h"
#include "framework/ecs/component_array_container.h"
#include "framework/ecs/system.h"
#include "context.h"

#include "maths/maths_types.h"

#include "util/logger.h"

namespace HGE {

    /**
     * World Position IComponent
     */
    struct PositionComponent : public IComponent {
        Transform2f mTransform;

        [[nodiscard]] const float &getX() const { return mTransform.mLocalPosition.x; }
        [[nodiscard]] const float &getY() const { return mTransform.mLocalPosition.y; }
        void setX(const float &value) { mTransform.mLocalPosition.x = value; }
        void setY(const float &value) { mTransform.mLocalPosition.y = value; }

        explicit PositionComponent(UID ownerId) : IComponent(ownerId), mTransform(Transform2f()) {}
        ~PositionComponent() override = default;
    };

    /**
     * World Position System
     */
    template<>
    class System<PositionComponent> : public ISystem {

    public:
        explicit System(Context* /*context*/, ComponentArray<PositionComponent> * /*componentArray*/) {
            Logger::instance()->logDebug("World Position System", "Created!");
        }
        ~System() override = default;

        void run(const double & /*deltaTime*/) override {}
    };
}// namespace HGE

#endif /* HESTIA_FRAMEWORK_WORLD_POSITION_H */