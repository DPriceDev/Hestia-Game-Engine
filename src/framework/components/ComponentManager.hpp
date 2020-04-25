#ifndef HESTIA_FRAMEWORK_COMPONENTS_COMPONENTMANAGER_H_
#define HESTIA_FRAMEWORK_COMPONENTS_COMPONENTMANAGER_H_

#include <map>
#include <vector>
#include <string>

#include "Component.hpp"
#include "../src/util/Logger.hpp"

// TODO: Switch to returning a number for the component?
// TODO: Better way of deleting the components, or ordering? an array??

/**
 * Component Manager
 */
class ComponentManager {
    
    private:
    std::map<const char *, std::vector<Component*>> mMappedComponentArrays;

    void createNewMappedComponentArray(Component* component) {
        mMappedComponentArrays[component->getTag()] = std::vector<Component*>();
        LogDebug("New Array Created");
        addComponentToMappedArray(component);
        /** TODO: Create System to match newly inserted component. */
    }

    void addComponentToMappedArray(Component* component) {
        mMappedComponentArrays[component->getTag()].push_back(component);
        LogDebug("Component added to array");
    }

    bool doesKeyExistInMappedArrays(const char * key) {
        return mMappedComponentArrays.find(key) != mMappedComponentArrays.end();
    }

    public:
    void registerComponent(Component* component) {
        if(doesKeyExistInMappedArrays(component->getTag())) {
            addComponentToMappedArray(component);
        } else {
            createNewMappedComponentArray(component);
        }
    }

    void unregisterComponent(Component* component) {
        // TODO: Add in code to unregister
    }

    ComponentManager() {
        mMappedComponentArrays = std::map<const char *, std::vector<Component*>>();
    }

    ~ComponentManager() { }
};

#endif