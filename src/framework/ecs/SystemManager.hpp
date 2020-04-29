#ifndef HESTIA_FRAMEWORK_ECS_SYSTEMMANAGER_H_
#define HESTIA_FRAMEWORK_ECS_SYSTEMMANAGER_H_

#include <set>

#include "System.hpp"
#include "../src/util/Logger.hpp"

namespace HGE {
    
    class SystemManager {
        
        private:
        std::set<System*> mSystems;

        public:
        template<class T>
        void registerSystem() {
            T* system = new T();
            mSystems.insert(system);
            LogDebug("System Registered");
        }

        void run() {
            for(auto & system : mSystems) {
                system->run();
            }
        }
    };
}

#endif