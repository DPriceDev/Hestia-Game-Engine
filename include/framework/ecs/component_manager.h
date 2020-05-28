#ifndef HESTIA_FRAMEWORK_ECS_COMPONENT_MANAGER_H
#define HESTIA_FRAMEWORK_ECS_COMPONENT_MANAGER_H

#include <algorithm>
#include <map>
#include <memory>
#include <string>
#include <typeinfo>
#include <vector>

#include "component.h"
#include "system_manager.h"

#include "util/logger.h"

namespace HGE {
    using UID = int;

    class ComponentManager {
        std::map<std::string, std::unique_ptr<IComponentArray>> mTypedComponentArrays;
        SystemManager *mSystemManager;

    public:
        explicit ComponentManager(SystemManager *pSystemManager)
            : mTypedComponentArrays(std::map<std::string, std::unique_ptr<IComponentArray>>()),
              mSystemManager(pSystemManager) {}

        ~ComponentManager() = default;
        ComponentManager &operator=(const ComponentManager &other) = delete;

        /* Create a component vector within the typed component map. returns the vector. */
        template<typename Comp>
        ComponentArray<Comp> *createComponentArray() {
            auto type = typeid(Comp).name();
            mTypedComponentArrays[type] = std::make_unique<ComponentArray<Comp>>();
            auto componentArray = dynamic_cast<ComponentArray<Comp> *>(mTypedComponentArrays[type].get());
            mSystemManager->createSystem<Comp>(componentArray);
            // LOG_DEBUG("IComponent Manager", "IComponent Array created:", type)
            return componentArray;
        }

        /* Creates a component and adds it to the corresponding typed vector. returns the component. */
        template<typename Comp, typename... Args>
        Comp *createComponent(Args &&... args) {
            auto type = typeid(Comp).name();
            auto it = mTypedComponentArrays.find(type);
            ComponentArray<Comp> *pArray;

            if (it == mTypedComponentArrays.end()) {
                pArray = createComponentArray<Comp>();
            } else {
                pArray = dynamic_cast<ComponentArray<Comp> *>(mTypedComponentArrays[type].get());
            }
            // LOG_DEBUG("IComponent Manager", "IComponent Created:", type);
            return pArray->mComponents.emplace_back(std::make_unique<Comp>(std::forward<Args>(args)...)).get();
        }

        /* Takes the pointer for a component and removes it from the selected component array, if it exists. */
        template<typename Comp>
        void deleteComponentByPtr(Comp *component) {
            auto type = typeid(Comp).name();
            auto it = mTypedComponentArrays.find(type);

            if (it != mTypedComponentArrays.end()) {
                it->second->deleteComponentWithOwner(component->getOwnerUID());
            }
        }

        /* deletes a component by its owning id, if it exists. */
        template<typename Comp>
        void deleteComponentById(UID ownerId) {
            auto type = typeid(Comp).name();
            auto it = mTypedComponentArrays.find(type);

            if (it != mTypedComponentArrays.end()) {
                it->second->deleteComponentWithOwner(ownerId);
            }
        }

        /* Get the component vector for the given type. creates and returns the vector if it doesn't exist. */
        template<typename Comp>
        ComponentArray<Comp> *getComponentArray() {
            auto type = typeid(Comp).name();
            auto it = mTypedComponentArrays.find(type);

            if (it == mTypedComponentArrays.end()) {
                return createComponentArray<Comp>();
            } else {
                return dynamic_cast<ComponentArray<Comp> *>(mTypedComponentArrays[type].get());
            }
        }
    };
}// namespace HGE

#endif