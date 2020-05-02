#ifndef UIDLIB_HPP
#define UIDLIB_HPP

/**
 * 
 * TODO: Create a better way of generating and reusing id's.
 * TODO: Integrate with object manager?
 */
static int GenerateUniqueId() {
    static int id = 0;
    return ++id;
}

#endif