#ifndef HESTIA_FRAMEWORK_ECS_SYSTEMMANAGER_H_
#define HESTIA_FRAMEWORK_ECS_SYSTEMMANAGER_H_

#include <set>
#include <memory>

#include "System.hpp"
#include "util/Logger.hpp"

namespace HGE {
    
    class SystemManager {
        
        private:
        std::set<std::unique_ptr<System>> mSystems;

        public:
        template<class T>
        void registerSystem() {
            mSystems.insert(std::unique_ptr<T>(new T()));
            Logger::getInstance()->logDebug("System Manager","System Registered");
        }

        void run() {
            for(auto & system : mSystems) {
                system->run();
            }
        }
    };
}

#endif