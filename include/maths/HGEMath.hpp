#ifndef HESTIA_MATHS_HGE_MATHES_HPP_
#define HESTIA_MATHS_HGE_MATHES_HPP_

#include "MathsTypes.hpp"

namespace HGE {

    static void randomFloatBetween(float& out, float min, float max) {
        out = min + (rand() / (RAND_MAX / (max-min)));
    }
}


#endif