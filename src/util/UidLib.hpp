#ifndef UIDLIB_HPP
#define UIDLIB_HPP

static long GenerateUniqueId() {
    static unsigned long long int id = 0;
    return ++id;
}

#endif