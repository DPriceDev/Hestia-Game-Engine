#ifndef HESTIA_FRAMEWORK_ECS_COMPONENT_H
#define HESTIA_FRAMEWORK_ECS_COMPONENT_H

#include <vector>
#include <string>
#include <memory>
#include <algorithm>

#include "util/Uid.h"
#include "util/Logger.h"

namespace HGE {
    using UID = int;

    /**
     * IComponent Interface
     */
    class IComponent {

        UID mOwnerUID;

        public:
        IComponent(UID ownerId) : mOwnerUID(ownerId) { }
        virtual ~IComponent() = default;
        
        UID getOwnerUID() const {
            return mOwnerUID; 
        }
    };

    /**
     * IComponent Array Interface
     */
    class IComponentArray {
        public:
        virtual ~IComponentArray() = default;
    };

    /**
     * IComponent Array
     */
    template <class C>
    class ComponentArray : public IComponentArray {
        std::vector<std::unique_ptr<C>> mComponents;
        friend class ComponentManager;

        public:
        ComponentArray() : mComponents(std::vector<std::unique_ptr<C>>()) { }
        ~ComponentArray() override = default;
        ComponentArray& operator= (const ComponentArray &other) = delete;

        std::vector<std::unique_ptr<C>>& getComponents() { return mComponents; }

        C* getComponentWithOwner(UID ownerId) {
            auto it = std::find_if(
                mComponents.begin(), 
                mComponents.end(),
                [&] (const auto &pComponent) { return pComponent->getOwnerUID() == ownerId; });

            if(it != mComponents.end()) {
                return it->get();
            } else {
                return nullptr;
            }
        }
    };
}

#endif