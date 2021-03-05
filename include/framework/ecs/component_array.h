//
// Created by David Price on 04/03/2021.
//

#ifndef HESTIA_FRAMEWORK_ECS_COMPONENT_ARRAY_H
#define HESTIA_FRAMEWORK_ECS_COMPONENT_ARRAY_H

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "component.h"

namespace HGE {

    /**
     * Component Array Interface
     * Defines a component array regardless of component type.
     * todo: rename to ComponentArray
     * todo: is this or could this be a type erased container?
     * todo: move to own class?
     */
    class IComponentArray {
    public:
        virtual ~IComponentArray() = default;
        virtual void deleteComponentWithOwner(UID id) = 0;
    };

    /**
     * Component Array
     * This class contains an array of components of template type C.
     * It provides methods to get and delete components in this array.
     * todo: this is a friend class of Component manager, why? how are components added?
     * todo: rename to ComponentArrayImpl?
     */
    template<component Comp>
    class ComponentArray : public IComponentArray {
        std::vector<std::unique_ptr<Comp>> mComponents;
        friend class ComponentArrayContainer;

    public:
        /* RAII */
        ComponentArray() : mComponents(std::vector<std::unique_ptr<Comp>>()) {}
        ~ComponentArray() override = default;
        ComponentArray &operator=(const ComponentArray &other) = delete;

        /* Getters */
        std::vector<std::unique_ptr<Comp>> &getComponents() { return mComponents; }

        /* Gets a component for a given owner id. Returns Component C from template */
        Comp *getComponentWithOwner(const UID ownerId) const {
            auto it = std::find_if(
                    mComponents.begin(),
                    mComponents.end(),
                    [&](const auto &pComponent) { return pComponent->getOwnerUID() == ownerId; });

            if (it != mComponents.end()) {
                return it->get();
            } else {
                return nullptr;
            }
        }

        /* Add Component to back of the component Array */
        // todo: extract create component responsibility?
        template<typename... Args>
        Comp* createComponent(Args &&... args) {
            return mComponents.emplace_back(std::make_unique<Comp>(std::forward<Args>(args)...)).get();
        }

        /* Deletes a component from the owning object id. overrides interface. */
        void deleteComponentWithOwner(const UID ownerId) override {
            auto it = std::find_if(
                    mComponents.begin(),
                    mComponents.end(),
                    [&](const auto &pComponent) { return pComponent->getOwnerUID() == ownerId; });

            if (it != mComponents.end()) {
                mComponents.erase(it);
            }
        }
    };

    /* */
    template<typename C>
    concept componentArray = std::is_base_of<IComponentArray, C>::value;
}

#endif //HESTIA_FRAMEWORK_ECS_COMPONENT_ARRAY_H
