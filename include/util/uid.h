#ifndef HESTIA_UTIL_UID_H
#define HESTIA_UTIL_UID_H

class IdGenerator {

public:
    /**
     *
     * TODO: Create a better way of generating and reusing id's.
     * TODO: Integrate with object manager?
     */
    static int GenerateUniqueId() {
        static int id = 0;
        return id++;
    }
};

#endif