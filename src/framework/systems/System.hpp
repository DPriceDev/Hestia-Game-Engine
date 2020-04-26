#ifndef HESTIA_FRAMEWORK_SYSTEMS_SYSTEM_H_
#define HESTIA_FRAMEWORK_SYSTEMS_SYSTEM_H_

#include "../src/framework/components/Component.hpp"

/**
 * System Interface
 */
class System {
    
    private:
    std::vector<Component*>* mComponentArray;

    public:
    ~System() { }
};

#endif