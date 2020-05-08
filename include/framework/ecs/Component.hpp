#ifndef HESTIA_FRAMEWORK_ECS_COMPONENT_HPP_
#define HESTIA_FRAMEWORK_ECS_COMPONENT_HPP_

#include <string>

namespace HGE {
    using UID = int;
    class Component {

        UID mOwnerUID;

        public:
        Component(UID ownerId) : mOwnerUID(ownerId) { }
        virtual ~Component() = default;
        
        UID getOwnerUID() const { 
            return mOwnerUID; 
        }
    };
}

#endif