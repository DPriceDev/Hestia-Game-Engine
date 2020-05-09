#ifndef HESTIA_FRAMEWORK_ECS_SYSTEM_H
#define HESTIA_FRAMEWORK_ECS_SYSTEM_H

#include "util/Uid.h"
#include "util/Logger.h"


namespace HGE {

    /**
     * System Interface
     */
    class ISystem {
        public:
        virtual void run() = 0;
        virtual ~ISystem() = default;
    };

    /**
     * System Template
     */
    template <class C>
    class System : public ISystem {

        System() = default;
        public:
        ~System() = default;
        void run() = 0;
    };
}

#endif