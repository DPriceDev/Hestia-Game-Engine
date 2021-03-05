#ifndef HESTIA_FRAMEWORK_ECS_OBJECT_H
#define HESTIA_FRAMEWORK_ECS_OBJECT_H


#include "util/logger.h"
#include "util/uid.h"


namespace HGE {
    using UID = int;

    /**
     * Object Interface
     * Defines the base object (entity) for the ECS framework.
     * This Class provides a unique ID for the object to be identified in the components and systems.
     * This Class provides a virtual 'onCreate' method that provides a unified initialization for the object.
     * todo: rename to Object? or Entity?
     */
    class IObject {
        // todo: extract implementation from class, to provide multiple id areas.
        UID id = IdGenerator::GenerateUniqueId();

    public:
        // RAII
        virtual ~IObject() = default;

        // On Create
        virtual void onCreate() = 0;

        // Getters
        [[nodiscard]] virtual UID getId() const {
            return id;
        }
    };

    // todo: A concept would allow better template definition for this object class
    //        template<typename O>
    //        concept object = std::is_base_of<IObject, O>::value;
}// namespace HGE

#endif