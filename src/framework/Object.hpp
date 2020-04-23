#ifndef OBJECT_HPP
#define OBJECT_HPP

/**
 * Object
 */
class Object {

    public:
    /* Constructor */
    Object(long id) : id(id) { }

    /* Destructor */
    ~Object() { }

    long getId() {
       return id;
    }

    /* Public Methods */

    private:
    long id;
};

#endif