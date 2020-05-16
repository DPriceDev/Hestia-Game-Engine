#ifndef HESTIA_MATHS_HGE_MATHS_H
#define HESTIA_MATHS_HGE_MATHS_H

#include <random>
#include <cmath>

#include "maths_types.h"

namespace HGE {

    template<typename T>
    static T randomNumberBetween(T minimum, T maximum) {
        std::mt19937 mt{std::random_device{}()};
        std::uniform_int_distribution<T> dist(minimum, maximum);
        return dist(mt);
    }

    template<typename T>
    static T roundValueToMultipleOf(T value, T multiple) {
        return floor(((value + multiple - 1)/multiple)) * multiple;
    }
}


#endif