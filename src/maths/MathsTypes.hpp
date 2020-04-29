#ifndef HESTIA_FRAMEWORK_MATHS_MATHSTYPES_HPP_
#define HESTIA_FRAMEWORK_MATHS_MATHSTYPES_HPP_

#include <array>

namespace HGE {

    struct Vector2f {
        float x, y;

        Vector2f() : x(0), y(0) { }

        Vector2f(float x, float y) : x(x), y(y) { }

        void setXY(float x, float y) {
            x = x;
            y = y;
        }

        std::array<float, 2> asArray2f() {
            return {x, y};
        }

        std::array<float, 3> asArray3f() {
            return {x, y, 0.0};
        }
    };

    struct Vector3f {
        float x, y, z;

        Vector3f(float x, float y, float z) : x(x), y(y), z(z) { }

        std::array<float, 3> asArray3f() {
            return {x, y, z};
        }
    };

    struct Transform2f {

        Transform2f(Vector2f localPosition = Vector2f(), float rotation = 0, float scale = 1) { }
        
        Vector2f mLocalPosition;
        float mRotation;
        float mScale;
    };

}

#endif