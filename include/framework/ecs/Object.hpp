#ifndef HESTIA_FRAMEWORK_ECS_OBJECT_HPP_
#define HESTIA_FRAMEWORK_ECS_OBJECT_HPP_

#include <vector>

#include "Component.hpp"
#include "util/UidLib.hpp"

namespace HGE {
    using UID = int;

    class Object {

        protected:
        UID id = GenerateUniqueId();

        public:
        virtual ~Object() = default;

        /* Setters and Getters */
        UID getId() const {
        return id;
        }

        /* Public Methods */
        virtual void onCreate() = 0;
        virtual void tick(double deltaTime) = 0;
    };
}
#endif