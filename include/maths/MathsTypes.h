#ifndef HESTIA_FRAMEWORK_MATHS_MATHSTYPES_H
#define HESTIA_FRAMEWORK_MATHS_MATHSTYPES_H

#include <array>
#include <iostream>

namespace HGE {

    struct Vector2f;
    struct Vector3f;
    struct Vector4f;
    struct Transform2f;

    using Pointi = int;
    using Pointf = float;
    using Pointd = double;
    using Rotf = float;
    using Scalef = float;
    using ColourRGB = Vector3f;
    using ColourRGBA = Vector4f;

    // todo: template out vector2f
    // todo: maybe vector out the 2?

    struct Vector2i {
        Pointi x, y;

        Vector2i() : x(0), y(0) { }

        Vector2i(Pointi x, Pointi y) : x(x), y(y) { }

        explicit Vector2i(Pointi xy) : x(xy), y(xy) { }

        static void setXY(Pointi x, Pointi y) {
            x = x;
            y = y;
        }

        std::array<Pointi, 2> asArray2f() {
            return {x, y};
        }
    };

    struct Vector2f {
        Pointf x, y;

        Vector2f() : x(0), y(0) { }

        Vector2f(Pointf x, Pointf y) : x(x), y(y) { }

        explicit Vector2f(Pointf xy) : x(xy), y(xy) { }

        Vector2f& operator-(const Vector2f& other) {
            this->x -= other.x;
            this->y -= other.y;
            return *this;
        }

        Vector2f& operator+(const Vector2f& other) {
            this->x += other.x;
            this->y += other.y;
            return *this;
        }

        inline Vector2f& operator+=(const Vector2f& other) {
            this->x += other.x;
            this->y += other.y;
            return *this;
        }

        inline const Vector2f& operator*(const float value) {
            this->x *= value;
            this->y *= value;
            return *this;
        }

        inline Vector2f& operator/(const float value) {
            this->x /= value;
            this->y /= value;
            return *this;
        }

        Vector2f& operator-=(const Vector2f& other) {
             this->x -= other.x;
             this->y -= other.y;
             return *this;
        }

        bool operator==(const Vector2f& other) const {
            return this->x == other.x
            && this->y == other.y;
        }

        bool operator!=(const Vector2f& other) const {
            return this->x != other.x
                   || this->y != other.y;
        }

        void setXY(Pointf x, Pointf y) {
            this->x = x;
            this->y = y;
        }

        [[nodiscard]]
        Pointf magnitude() const {
            return sqrt((x * x) + (y * y));
        }

        [[nodiscard]]
        Vector2f normalised() const {
            return { this->x/magnitude(), this->y/magnitude() };
        }

        std::array<Pointf, 2> asArray2f() {
            return {x, y};
        }

        std::array<Pointf, 3> asArray3f() {
            return {x, y, 0.0};
        }
    };

    struct Vector2d {
        Pointd x, y;

        Vector2d() : x(0), y(0) { }

        Vector2d(Pointd x, Pointd y) : x(x), y(y) { }

        explicit Vector2d(Pointd xy) : x(xy), y(xy) { }

        static void setXY(Pointd x, Pointd y) {
            x = x;
            y = y;
        }

        std::array<Pointd, 2> asArray2f() {
            return {x, y};
        }

        std::array<Pointd, 3> asArray3f() {
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

    struct Rectf {
        Vector2f mPosition;
        Vector2f mSize;

        Rectf(Vector2f position, Vector2f size) : mPosition(position), mSize(size) { }
        Rectf() : mPosition(Vector2f()), mSize(Vector2f()) { }

        [[nodiscard]]
        Vector2f bottomLeft() const {
            return mPosition;
        }

        [[nodiscard]]
        Vector2f bottomRight() const {
            return {mPosition.x + mSize.x, mPosition.y};
        }

        [[nodiscard]]
        Vector2f topLeft() const {
            return {mPosition.x, mPosition.y + mSize.y};
        }

        [[nodiscard]]
        Vector2f topRight() const {
            return {mPosition.x + mSize.x, mPosition.y + mSize.y};
        }

        [[maybe_unused]]
        [[nodiscard]]
        bool isOverlapping(const Rectf& other) const {
            if (this->topLeft().x >= other.bottomRight().x
            || other.topLeft().x >= this->bottomRight().x) {
                return false;
            }

            return !(this->topLeft().y <= other.bottomRight().y
                     || other.topLeft().y <= this->bottomRight().y);
        }

        [[maybe_unused]]
        [[nodiscard]]
        Vector2f midpoint() const {
            return {mPosition.x + (mSize.x/2.0f), mPosition.y + (mSize.y/2.0f) };
        }
    };
}

#endif