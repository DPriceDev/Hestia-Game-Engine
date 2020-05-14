#ifndef HESTIA_FRAMEWORK_ECS_OBJECT_H
#define HESTIA_FRAMEWORK_ECS_OBJECT_H

#include <tuple>
#include <vector>
#include <memory>

#include "framework/ecs/ComponentManager.h"
#include "framework/ecs/IComponent.h"
#include "util/Uid.h"
#include "util/Logger.h"


namespace HGE {
    using UID = int;

    /**
     * Object Interface
     */
    class IObject {
        UID id = GenerateUniqueId();

        public:
        virtual ~IObject() = default;
        [[nodiscard]] virtual UID getId() const {
            return id;
        }
        virtual void onCreate() = 0;
    };

    /**
     * Object Templated Class
     */
    class Object : public IObject {

    public:
        Object() = default;
        ~Object() override = default;

        /* Public Methods */
        void onCreate() override = 0;
    };
}

#endif