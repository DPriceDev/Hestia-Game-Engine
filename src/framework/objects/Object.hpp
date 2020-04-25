#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "../src/util/UidLib.hpp"

/**
 * Object
 */
class Object {

    protected:
    long id = GenerateUniqueId();

    public:
    ~Object();

    /* Setters and Getters */
    long getId() {
       return id;
    }

    /* Public Methods */
    virtual void tick() = 0;
};

#endif