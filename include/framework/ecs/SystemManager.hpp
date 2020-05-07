#ifndef HESTIA_FRAMEWORK_ECS_SYSTEMMANAGER_H_
#define HESTIA_FRAMEWORK_ECS_SYSTEMMANAGER_H_

#include <set>
#include <memory>
#include <functional>

#include "System.hpp"
#include "util/Logger.hpp"

namespace HGE {

    class SystemManager {
        std::vector<ISystem> mSystems;

        public:
        SystemManager() : mSystems(std::vector<ISystem>()){ }
        ~SystemManager() { }

        template <class C>
        System<C>* createSystem() {

        }

        template <class C>
        void deleteSystem() {

        }

        template <class C>
        System<C>* getSystem() {

        }

        void run() {
            
        }
    };

















    // class SystemManager {
    //     std::set<std::unique_ptr<ISystem>> mSystems;

    //     public:
    //     template<class T>
    //     ISystem* createSystem() {
    //         auto it = mSystems.insert(std::make_unique<T>());
    //         Logger::getInstance()->logDebug("System Manager", "System Created!");
    //         return it.first->get();
    //     }

    //     template<class C>
    //     void registerComponent(Component* component) {


    //         auto set = std::set<ISystem>();

    //         auto it = mSystems.insert(std::unique_ptr<ISystem>(System<C>()));

    //         //std::cout << "System created" << it.first->get() << "\n";

    //         Logger::getInstance()->logDebug("System Manager", "Register Component called!");
    //         //return it.first->get();
    //     }

    //     template<class C>
    //     void deregisterComponent(Component* component) {
    //         Logger::getInstance()->logDebug("System Manager", "de-register Component called!");
    //         std::cout << "De register!\n";
    //     }

    //     void destroySystem(ISystem* pSystem) {
    //         mSystems.erase( std::find_if(mSystems.begin(), mSystems.end(),
    //             [pSystem] (const std::unique_ptr<ISystem> &s) { return s.get() == pSystem; } ));
    //     }

    //     void run() {
    //         for(auto & system : mSystems) {
    //             system->run();
    //         }
    //     }
    // };
}

#endif