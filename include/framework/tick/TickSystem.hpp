#ifndef HESTIA_TICK_TICK_SYSTEM_HPP_
#define HESTIA_TICK_TICK_SYSTEM_HPP_

#include <vector>

#include "framework/ecs/System.hpp"
#include "framework/ecs/Component.hpp"

#include "util/Logger.hpp"

#include "TickComponent.hpp"

namespace HGE {
    
    class TickSystem : public System {

        private:
        std::vector<Component*>* mComponents; 

        public:
        TickSystem();

        ~TickSystem() {
        }

        void run() override;
    };
}

#endif