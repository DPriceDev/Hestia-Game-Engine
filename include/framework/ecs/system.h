#ifndef HESTIA_FRAMEWORK_ECS_SYSTEM_H
#define HESTIA_FRAMEWORK_ECS_SYSTEM_H

#include "util/uid.h"
#include "util/logger.h"


namespace HGE {

    /**
     * System Interface
     */
    class ISystem {
        public:
        virtual void run(const double& deltaTime) = 0;
        virtual ~ISystem() = default;
    };

    /**
     * System Template
     */
    template <class C>
    class System : public ISystem {

        System() = default;
        public:
        ~System() override = default;
        void run(const double& deltaTime) override = 0;
    };
}

#endif