#ifndef HESTIA_FRAMEWORK_ECS_COMPONENTMANAGER_H_
#define HESTIA_FRAMEWORK_ECS_COMPONENTMANAGER_H_

#include <map>
#include <vector>
#include <string>

#include "Component.hpp"
#include "../src/util/Logger.hpp"

namespace HGE {
    
    class ComponentManager {
        
        private:
        std::map<const char *, std::vector<Component*>*> mMappedComponentArrays;

        /* Creates a new component array for the provided component, mapped to the component tag. */
        std::vector<Component*>* createNewMappedComponentArray(Component* component) {
            auto pArray = new std::vector<Component*>();
            mMappedComponentArrays[component->getTag()] = pArray;

            component->registerSystem();

            LogDebug("New Array Created");

            return pArray;
        }

        /* Adds a component to its corrosponding array within the component array map. */
        void addComponentToMappedArray(Component* component) {
            mMappedComponentArrays[component->getTag()]->push_back(component);
            LogDebug("Component added to array");
        }

        /* Checks if a component array exists within the map by the component tag. */
        bool doesKeyExistInMappedArrays(const char * key) {
            return mMappedComponentArrays.find(key) != mMappedComponentArrays.end();
        }

        public:
        /* registers a component to the component manager. */
        void registerComponent(Component* component) {
            if(doesKeyExistInMappedArrays(component->getTag())) {
                addComponentToMappedArray(component);
            } else {
                createNewMappedComponentArray(component);
                addComponentToMappedArray(component);
            }
        }

        /* Retrieves a component array for the given T component class. creates a new array if missing. */
        template <class T>
        std::vector<Component*>* getComponentArray() {

            T* component = new T();

            LogDebug("Component array retrieved.");

            if(!doesKeyExistInMappedArrays(component->getTag())) {
                return createNewMappedComponentArray(component);
            }

            auto pArray = mMappedComponentArrays[component->getTag()];

            return pArray;
        }

        /** Constructors and Deconstructors */
        ComponentManager() {
            mMappedComponentArrays = std::map<const char *, std::vector<Component*>*>();
        }

        ~ComponentManager() { }
    };
}

#endif