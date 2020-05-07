#ifndef HESTIA_FRAMEWORK_ECS_SYSTEM_H_
#define HESTIA_FRAMEWORK_ECS_SYSTEM_H_

#include <vector>
#include <memory>

#include "Component.hpp"
#include "framework/sprite/SpriteComponent.hpp"
#include "util/Logger.hpp"

namespace HGE {


    class ISystem {
        public:
        virtual void run() = 0;
        virtual ~ISystem() = default;
    };

    template <class C>
    class System : public ISystem {

        public:
        System() { }
        ~System() { }

        void run() override { }
    };
}
#endif