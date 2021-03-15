#ifndef HESTIA_FRAMEWORK_ECS_SYSTEMMANAGER_H
#define HESTIA_FRAMEWORK_ECS_SYSTEMMANAGER_H

#include <functional>
#include <map>
#include <memory>
#include <typeinfo>

#include "system.h"
#include "util/logger.h"

#include "context.h"

namespace HGE {

    class SystemManager {
        std::map<std::string, std::unique_ptr<ISystem>> mTypedSystems;

    public:
        /* RAII */
        SystemManager() : mTypedSystems(std::map<std::string, std::unique_ptr<ISystem>>()) {}

        ~SystemManager() = default;

        SystemManager &operator=(const SystemManager &other) = delete;

        /* create a system for a given component. return the system if it already exists. */
        template<ComponentConcept C, class... Args>
        const System <C> *createSystem(Args &&... args) {
            auto type = typeid(System<C>).name();
            auto it = mTypedSystems.find(type);

            if (it != mTypedSystems.end()) {
                return dynamic_cast<System<C> *>(it->second.get());
            } else {
                mTypedSystems[type] = std::make_unique<System<C>>(std::forward<Args>(args)...);
                return dynamic_cast<System<C> *>(mTypedSystems[type].get());
            }
        }

        /* TODO: Add method to delete a system by its templated class */
        template<ComponentConcept C>
        void deleteSystem() {
        }

        /* TODO: Add method to get a system by its templated class */
        template<ComponentConcept C>
        System <C> *getSystem() {
        }

        /* Runs all of the systems with a provided delta time */
        // todo: how are these systems ordered? should it have a zorder? or grouped into phases?
        // todo: extract to free function?
        void run(const double &deltaTime) const {
            for (auto const &typedSystem : mTypedSystems) {
                typedSystem.second->run(deltaTime);
            }
        }
    };
}// namespace HGE

#endif