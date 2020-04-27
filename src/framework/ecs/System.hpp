#ifndef HESTIA_FRAMEWORK_ECS_SYSTEM_H_
#define HESTIA_FRAMEWORK_ECS_SYSTEM_H_

#include "Component.hpp"

/**
 * System Interface
 */
class System {
    
    protected:
    std::vector<Component*>* mComponentArray;

    public:
    virtual void run() = 0;

    ~System() { }
};

#endif