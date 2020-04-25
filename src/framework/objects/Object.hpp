#ifndef HESTIA_FRAMEWORK_OBJECTS_OBJECT_HPP_
#define HESTIA_FRAMEWORK_OBJECTS_OBJECT_HPP_

#include <vector>

#include "../src/framework/components/Component.hpp"
#include "../src/util/UidLib.hpp"

/**
 * Object
 */
class Object {

    protected:
    long id = GenerateUniqueId();
    std::vector<Component*> mComponents;

    public:
    ~Object() { }

    /* Setters and Getters */
    long getId() const {
       return id;
    }

    /* Public Methods */
    virtual void tick() = 0;

    std::vector<Component*> getComponents() {
        return mComponents;
    }
};

#endif