#ifndef HESTIA_FRAMEWORK_MATHS_MATHSTYPES_H
#define HESTIA_FRAMEWORK_MATHS_MATHSTYPES_H

#include <array>

namespace HGE {

    struct Vector2f;
    struct Vector3f;
    struct Vector4f;
    struct Transform2f;
    
    using Pointf = float;
    using Rotf = float;
    using Scalef = float;
    using ColourRGB = Vector3f;
    using ColourRGBA = Vector4f;

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

        Vector3f() : x(0.0f), y(0.0f), z(0.0f) { }
        Vector3f(Pointf x, Pointf y, Pointf z) : x(x), y(y), z(z) { }

        std::array<Pointf, 3> asArray3f() {
            return {x, y, z};
        }
    };

        struct Vector4f {
        Pointf x, y, z, w;

        Vector4f() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }
        Vector4f(Pointf x, Pointf y, Pointf z, Pointf w) : x(x), y(y), z(z), w(w) { }

        std::array<Pointf, 4> asArray4f() {
            return {x, y, z, w};
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