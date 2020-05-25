#ifndef HESTIA_MATHS_HGE_MATHS_H
#define HESTIA_MATHS_HGE_MATHS_H

#include <random>
#include <cmath>

#include <athena/include/athena_functions.h>
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

    template<typename V, typename T>
    static T ceilToType(V value) {
        return static_cast<T>(ceil(value));
    }

    static bool isPointInACircle(const Vector2f &point, const Vector2f &center, const Pointf &radius) {
        return sqrt(((point.x - center.x) * (point.x - center.x))
                        + ((point.y - center.y) * (point.y - center.y))) <= radius;
    }

    static Vector2f midpointBetween(const Vector2f &a, const Vector2f &b) {
        return { (a.x + b.x) * 0.5f, (a.y + b.y) * 0.5f };
    }
}


#endif