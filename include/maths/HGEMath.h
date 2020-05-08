#ifndef HESTIA_MATHS_HGE_MATHS_H
#define HESTIA_MATHS_HGE_MATHS_H

#include "MathsTypes.h"

namespace HGE {

    static void randomFloatBetween(float& out, float min, float max) {
        out = min + (rand() / (RAND_MAX / (max-min)));
    }
}


#endif