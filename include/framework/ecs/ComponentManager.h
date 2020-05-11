#ifndef HESTIA_FRAMEWORK_ECS_COMPONENTMANAGER_H
#define HESTIA_FRAMEWORK_ECS_COMPONENTMANAGER_H

#include <map>
#include <typeinfo>
#include <vector>
#include <string>
#include <memory>
#include <iostream>

#include "Component.h"
#include "SystemManager.h"

#include "util/Logger.h"

namespace HGE {
    using UID = int;

    class ComponentManager {
        std::map<std::string, std::unique_ptr<IComponentArray>> mTypedComponentArrays;
        SystemManager* mSystemManager;

        public:
        ComponentManager() : mTypedComponentArrays(std::map<std::string, std::unique_ptr<IComponentArray>>()) { }
        ~ComponentManager() = default;
        ComponentManager& operator= (const ComponentManager &other) = delete;

        /* Assign the System manager. */
        void setSystemManager(SystemManager* pSystemManager) { 
            mSystemManager = pSystemManager; 
        }

        /* Create a component vector within the typed component map. returns the vector. */
        template <class C>
        ComponentArray<C>* createComponentArray() {
            auto type = typeid(C).name();
            mTypedComponentArrays[type] = std::make_unique<ComponentArray<C>>();
            auto componentArray = dynamic_cast<ComponentArray<C>*>(mTypedComponentArrays[type].get());
            mSystemManager->createSystem<C>(componentArray);
            Logger::instance()->logDebug("Component Manager", "Component Array created:", type, "ptr:", componentArray);
            return componentArray;
        }

        /* Creates a component and adds it to the corresponding typed vector. returns the component. */
        /* TODO: Check if need to delete pointer?? */
        template <class C, typename ... Args>
        C* createComponent(Args&& ... args) {
            auto type = typeid(C).name();
            auto it = mTypedComponentArrays.find(type);
            ComponentArray<C>* pArray;

            if(it == mTypedComponentArrays.end()) {
                pArray = createComponentArray<C>();
            } else {
                pArray = dynamic_cast<ComponentArray<C>*>(mTypedComponentArrays[type].get());
            }
            pArray->mComponents.push_back(std::make_unique<C>(std::forward<Args>(args)...));
            Logger::instance()->logDebug("Component Manager", "Component Created:", type, "ptr:", pArray->mComponents.back().get());
            return pArray->mComponents.back().get();
        }

        /* Takes the pointer for a component and removes it from the selected component array, if it exists. */
        template <class C>
        void deleteComponent(C* component) {
            auto type = typeid(C).name();
            auto it = mTypedComponentArrays.find(type);

            if(it != mTypedComponentArrays.end()) {
                auto pArray = dynamic_cast<ComponentArray<C>*>(mTypedComponentArrays[type].get());
                auto deleteIt = pArray.mComponents.find_if(pArray.mComponents.begin(), pArray.mComponents.end(), [&] (auto & arrayComponent) { 
                    return component->getOwnerUID() == arrayComponent.getOwnerUID();
                });
                pArray.mComponents.erase(deleteIt);
            }
        }

        /* deletes a component by its owning id, if it exists. */
        template <class C>
        void deleteComponent(UID ownerId) {
            auto type = typeid(C).name();
            auto it = mTypedComponentArrays.find(type);

            if(it != mTypedComponentArrays.end()) {
                auto pArray = dynamic_cast<ComponentArray<C>*>(mTypedComponentArrays[type].get());
                auto deleteIt = pArray.mComponents.find_if(pArray.mComponents.begin(), pArray.mComponents.end(), [&] (auto & arrayComponent) { 
                    return ownerId == arrayComponent.getOwnerUID();
                });
                pArray.mComponents.erase(deleteIt);
            }
        }

        /* Get the component vector for the given type. creates and returns the vector if it doesn't exist. */
        template <class C>
        ComponentArray<C>* getComponentArray() {
            auto type = typeid(C).name();
            auto it = mTypedComponentArrays.find(type);

            if(it == mTypedComponentArrays.end()) {
                return createComponentArray<C>();
            } else {
                return dynamic_cast<ComponentArray<C>*>(mTypedComponentArrays[type].get());
            }
        }
    };
}

#endif