#ifndef HESTIA_TICK_TICK_SYSTEM_HPP_
#define HESTIA_TICK_TICK_SYSTEM_HPP_

#include <vector>

#include "../src/framework/ecs/System.hpp"
#include "../src/framework/ecs/Component.hpp"

#include "../src/util/Logger.hpp"

#include "TickComponent.hpp"

/**
 * 
 */
class TickSystem : public System {

    private:
    std::vector<Component*>* mComponents; 

    public:
    TickSystem();

    ~TickSystem() {
    }

    void run() override;
};

#endif