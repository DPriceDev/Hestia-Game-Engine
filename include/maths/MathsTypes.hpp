#ifndef HESTIA_FRAMEWORK_MATHS_MATHSTYPES_HPP_
#define HESTIA_FRAMEWORK_MATHS_MATHSTYPES_HPP_

#include <array>

namespace HGE {
    using Pointf = float;
    using Rotf = float;
    using Scalef = float;

    struct Vector2f {
        Pointf x, y;

        Vector2f() : x(0), y(0) { }

        Vector2f(Pointf x, Pointf y) : x(x), y(y) { }

        Vector2f(Pointf xy) : x(xy), y(xy) { }

        void setXY(Pointf x, Pointf y) {
            x = x;
            y = y;
        }

        std::array<Pointf, 2> asArray2f() {
            return {x, y};
        }

        std::array<Pointf, 3> asArray3f() {
            return {x, y, 0.0};
        }
    };

    struct Vector3f {
        Pointf x, y, z;

        Vector3f(Pointf x, Pointf y, Pointf z) : x(x), y(y), z(z) { }

        std::array<Pointf, 3> asArray3f() {
            return {x, y, z};
        }
    };

    struct Transform2f {

        Vector2f mLocalPosition;
        Vector2f mScale;
        Rotf mRotation;

        Transform2f() : mLocalPosition(Vector2f()), 
                      mRotation(0.0f), 
                      mScale(1.0f) { }

        Transform2f(Vector2f localPosition, Rotf rotation, Scalef scale) 
                    : mLocalPosition(localPosition), 
                      mRotation(rotation), 
                      mScale(scale) { }

        Transform2f(Vector2f localPosition, Rotf rotation, Scalef scaleX, Scalef scaleY) 
                    : mLocalPosition(localPosition), 
                      mRotation(rotation), 
                      mScale(scaleX, scaleY) { }
    };
}

#endif