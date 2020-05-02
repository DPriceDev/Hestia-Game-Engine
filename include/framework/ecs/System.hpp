#ifndef HESTIA_FRAMEWORK_ECS_SYSTEM_H_
#define HESTIA_FRAMEWORK_ECS_SYSTEM_H_

#include <vector>

#include "Component.hpp"

namespace HGE {
    
    class System {
        
        protected:
        std::vector<Component*>* mComponentArray;

        public:
        virtual void run() = 0;

        virtual ~System() = default;
    };
}

#endif