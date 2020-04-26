#ifndef HESTIA_FRAMEWORK_SYSTEMS_SYSTEMMANAGER_H_
#define HESTIA_FRAMEWORK_SYSTEMS_SYSTEMMANAGER_H_

#include <set>

#include "System.hpp"
#include "../src/util/Logger.hpp"

/**
 * System Manager
 */
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

};

#endif