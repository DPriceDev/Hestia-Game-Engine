#ifndef HESTIA_FRAMEWORK_ECS_OBJECT_H
#define HESTIA_FRAMEWORK_ECS_OBJECT_H


#include "util/uid.h"
#include "util/logger.h"


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

//    template<typename O>
//    concept object = std::is_base_of<IObject, O>::value;
}

#endif