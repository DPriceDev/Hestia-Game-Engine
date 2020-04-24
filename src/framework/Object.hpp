#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "../util/UidLib.hpp"

/**
 * Object
 */
class Object {

    public:
    /* Constructor */
    Object() {
        id = GenerateUniqueId();
    }

    /* Destructor */
    ~Object();

    /* Setters and Getters */
    long getId() {
       return id;
    }

    /* Public Methods */
    virtual void tick() = 0;

    private:
    long id;
};

#endif