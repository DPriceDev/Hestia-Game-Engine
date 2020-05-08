#ifndef HESTIA_FRAMEWORK_ECS_SYSTEM_H_
#define HESTIA_FRAMEWORK_ECS_SYSTEM_H_

#include <vector>
#include <memory>

#include "Component.hpp"
#include "util/Logger.hpp"

namespace HGE {

    class ISystem {
        public:
        virtual void run() = 0;
        virtual ~ISystem() = default;
    };

    template <class C>
    class System : public ISystem {

        System() = default;
        public:
        ~System() = default;
        void run() = 0;
    };
}
#endif