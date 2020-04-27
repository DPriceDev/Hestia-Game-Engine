#ifndef HESTIA_TICK_TICK_COMPONENT_HPP_
#define HESTIA_TICK_TICK_COMPONENT_HPP_

#include <iostream>
#include <vector>
#include <functional>

#include "../src/framework/ecs/Component.hpp"

#include "../src/maths/MathsTypes.hpp"

#include "../src/util/Logger.hpp"

typedef void (*tickfunc_t)(float);

/**
 * Graphics Component
 * TODO: Switch off from a vector to array somehow?
 */
struct TickComponent : public Component {
    
    public:
    TickComponent() : Component("Tick") { 
    }

    ~TickComponent() { }

    void(mTickFunction) (float);

    void registerSystem() override;
};

#endif