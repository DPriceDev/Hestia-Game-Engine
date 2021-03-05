#ifndef HESTIA_FRAMEWORK_ECS_SYSTEM_H
#define HESTIA_FRAMEWORK_ECS_SYSTEM_H

#include "util/logger.h"
#include "util/uid.h"

namespace HGE {

    /**
     * System Interface
     * Defines an interface for the System in the ECS Framework.
     * Provides run method to allow systems to be run regardless of type.
     * todo: rename to system?
     */
    class ISystem {
    public:
        /* RAII */
        virtual ~ISystem() = default;

        /* Virtual method to run the system with a given delta time (time since last run) */
        virtual void run(const double &deltaTime) = 0;
    };

    /**
     * System Template
     * Provides the default template for a system, this is to be defined explicitly at the given callsite.
     * todo: is this needed? can it not just be defined as is?
     * todo: I imagine this is to do with assigning a system a component.
     * todo: rename to SystemImpl?
     * todo: pass a container of linked components perhaps?
     */
    template<class C>
    class System : public ISystem {

    public:
        System() = default;
        ~System() override = default;
        void run(const double &deltaTime) override = 0;
    };
}// namespace HGE

#endif