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
        Context* mContext;
        std::map<std::string, std::unique_ptr<ISystem>> mTypedSystems;

    public:
        SystemManager(Context* context) : mContext(context), mTypedSystems(std::map<std::string, std::unique_ptr<ISystem>>()) {}
        ~SystemManager() = default;
        SystemManager &operator=(const SystemManager &other) = delete;

        /* create a system for a given component. return the system if it already exists. */
        template<class C, class... Args>
        const System<C> *createSystem(Args &&... args) {
            auto type = typeid(System<C>).name();
            auto it = mTypedSystems.find(type);

            if (it == mTypedSystems.end()) {
                mTypedSystems[type] = std::make_unique<System<C>>(std::forward<Args>(args)...);
            }
            return dynamic_cast<System<C> *>(mTypedSystems[type].get());
        }

        /* */
        template<class C>
        void deleteSystem() {
        }

        /* */
        template<class C>
        System<C> *getSystem() {
        }

        /* */
        void run(const double &deltaTime) const {
            for (auto const &system : mTypedSystems) {
                system.second->run(deltaTime);
            }
        }
    };
}// namespace HGE

#endif