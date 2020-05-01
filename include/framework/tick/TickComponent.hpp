#ifndef HESTIA_TICK_TICK_COMPONENT_HPP_
#define HESTIA_TICK_TICK_COMPONENT_HPP_

#include <iostream>
#include <vector>
#include <functional>

#include "framework/ecs/Component.hpp"

#include "maths/MathsTypes.hpp"

#include "util/Logger.hpp"

typedef void (*tickfunc_t)(float);

namespace HGE {
    
    struct TickComponent : public Component {
        
        public:
        TickComponent() : Component("Tick") { 
        }

        ~TickComponent() { }

        void(mTickFunction) (float);

        void registerSystem() override;
    };
}

#endif