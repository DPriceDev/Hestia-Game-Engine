#ifndef HESTIA_FRAMEWORK_ECS_OBJECT_HPP_
#define HESTIA_FRAMEWORK_ECS_OBJECT_HPP_

#include <vector>

#include "Component.hpp"
#include "../src/util/UidLib.hpp"

/**
 * Object
 */
class Object {

    protected:
    long id = GenerateUniqueId();

    public:
    ~Object() { }

    /* Setters and Getters */
    long getId() const {
       return id;
    }

    /* Public Methods */
    virtual void onCreate() = 0;
    virtual void tick() = 0; 

    void registerComponent(Component* component);
};

#endif