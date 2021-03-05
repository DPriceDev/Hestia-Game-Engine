#ifndef HESTIA_FRAMEWORK_ECS_COMPONENT_H
#define HESTIA_FRAMEWORK_ECS_COMPONENT_H

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

namespace HGE {
    // todo: Extract to common?
    using UID = int;

    /**
     * Component Interface
     * Defines the Component of the ECS framework.
     * Contains a UID pointing to the owning 'Object' (entity).
     * todo: Rename to Component
     * todo: This could be a struct?
     */
    class IComponent {
        UID mOwnerUID;

    public:
        /* RAII */
        explicit IComponent(UID ownerId) : mOwnerUID(ownerId) {}
        virtual ~IComponent() = default;

        /* Getters */
        [[nodiscard]] UID getOwnerUID() const {
            return mOwnerUID;
        }
    };

    /* */
    template<typename C>
    concept component = std::is_base_of<IComponent, C>::value;

}// namespace HGE

#endif