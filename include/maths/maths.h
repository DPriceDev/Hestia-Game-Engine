#ifndef HESTIA_MATHS_HGE_MATHS_H
#define HESTIA_MATHS_HGE_MATHS_H

#include <cmath>
#include <random>

#include "maths_types.h"
#include <athena_functions.h>

namespace HGE {

    template<class T>
    static auto randomNumberBetween(const T minimum, const T maximum) -> T {
        //todo: static_assert((minimum < maximum), "Maximum is less than minimum.");
        std::mt19937 mt{std::random_device{}()};
        std::uniform_int_distribution<T> dist(minimum, maximum);
        return dist(mt);
    }

    template<class T>
    constexpr static auto roundValueToMultipleOf(const T value, const T multiple) -> T {
        return floor(((value + multiple - 1) / multiple)) * multiple;
    }

    template<class T, class V>
    constexpr static auto ceilToType(V value) -> T {
        return static_cast<T>(ceil(value));
    }

    static bool isPointInACircle(const Vector2f &point, const Vector2f &center, const Pointf &radius) {
        return sqrt(((point.x - center.x) * (point.x - center.x))
                    + ((point.y - center.y) * (point.y - center.y)))
               <= radius;
    }

//    static Vector2f midpointBetween(const Vector2f &a, const Vector2f &b) {
//        return {(a.x + b.x) * 0.5f, (a.y + b.y) * 0.5f};
//    }
}// namespace HGE


#endif