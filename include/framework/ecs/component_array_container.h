#ifndef HESTIA_FRAMEWORK_ECS_COMPONENT_MANAGER_H
#define HESTIA_FRAMEWORK_ECS_COMPONENT_MANAGER_H

#include <algorithm>
#include <map>
#include <memory>
#include <string>
#include <typeinfo>
#include <vector>
#include <optional>

#include "component_array.h"

#include "util/logger.h"

namespace HGE {
    using UID = int;

    /**
     * Component Manager
     * Takes a context object, and hold a map of component arrays of different component types.
     * todo: rename to ComponentArrayContainer?
     */
    class ComponentArrayContainer {
        std::map<std::string, std::unique_ptr<IComponentArray>> mTypedComponentArrays;

    public:
        /* RAII */
        explicit ComponentArrayContainer() : mTypedComponentArrays(std::map<std::string, std::unique_ptr<IComponentArray>>()) { }
        ~ComponentArrayContainer() = default;
        ComponentArrayContainer &operator=(const ComponentArrayContainer &other) = delete;

        /* Creates a component Array for the type Comp, and stores it in the map.
         * Returns the pointer to the created component array. */
        template<ComponentConcept Comp>
        ComponentArray<Comp> *createComponentArray() {
            auto type = typeid(Comp).name();
            mTypedComponentArrays[type] = std::make_unique<ComponentArray<Comp>>();
            return dynamic_cast<ComponentArray<Comp> *>(mTypedComponentArrays[type].get());
        }

        /* Retrieves a component array, returns nullopt if not present. */
        template<ComponentConcept Comp>
        std::optional<ComponentArray<Comp> *> getComponentArray() {
            auto type = typeid(Comp).name(); // todo: can this be compile time?
            auto it = mTypedComponentArrays.find(type);

            if (it == mTypedComponentArrays.end()) {
                return std::nullopt;
            } else {
                return dynamic_cast<ComponentArray<Comp> *>(it->second.get());
            }
        }
    };

}// namespace HGE

#endif