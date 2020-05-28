#ifndef HESTIA_FRAMEWORK_ECS_COMPONENT_H
#define HESTIA_FRAMEWORK_ECS_COMPONENT_H

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

namespace HGE {
    using UID = int;

    /**
     * IComponent Interface
     */
    class IComponent {

        UID mOwnerUID;

    public:
        explicit IComponent(UID ownerId) : mOwnerUID(ownerId) {}

        virtual ~IComponent() = default;

        [[nodiscard]] UID getOwnerUID() const {
            return mOwnerUID;
        }
    };

    //    /* Component concept requirement */
    //    template<typename C>
    //    concept component = std::is_base_of<IComponent, C>::value;

    /**
     * IComponent Array Interface
     */
    class IComponentArray {
    public:
        virtual ~IComponentArray() = default;
        virtual void deleteComponentWithOwner(UID id) = 0;
    };

    /**
     * IComponent Array
     */
    template<class C>
    class ComponentArray : public IComponentArray {
        std::vector<std::unique_ptr<C>> mComponents;
        friend class ComponentManager;

    public:
        ComponentArray() : mComponents(std::vector<std::unique_ptr<C>>()) {}
        ~ComponentArray() override = default;
        ComponentArray &operator=(const ComponentArray &other) = delete;

        std::vector<std::unique_ptr<C>> &getComponents() { return mComponents; }

        C *getComponentWithOwner(const UID ownerId) const {
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
}// namespace HGE

#endif