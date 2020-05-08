#ifndef HESTIA_FRAMEWORK_ECS_ECS_H
#define HESTIA_FRAMEWORK_ECS_ECS_H

#include <vector>
#include <string>
#include <memory>

#include "util/UidLib.hpp"
#include "util/Logger.hpp"

namespace HGE {
    using UID = int;

    /**
     * Object Interface
     */
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

    /**
     * Component Interface
     */
    class Component {

        UID mOwnerUID;

        public:
        Component(UID ownerId) : mOwnerUID(ownerId) { }
        virtual ~Component() = default;
        
        UID getOwnerUID() const { 
            return mOwnerUID; 
        }
    };

    /**
     * Component Array Interface
     */
    class IComponentArray {
        public:
        virtual ~IComponentArray() = default;
    };

    /**
     * Component Array
     */
    template <class C>
    class ComponentArray : public IComponentArray {
        std::vector<std::unique_ptr<C>> mComponents;
        friend class ComponentManager;

        public:
        ComponentArray() : mComponents(std::vector<std::unique_ptr<C>>()) { }
        ~ComponentArray() = default;
        ComponentArray& operator= (const ComponentArray &other) = delete;

        std::vector<std::unique_ptr<C>>& getComponents() { return mComponents; }
    };

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