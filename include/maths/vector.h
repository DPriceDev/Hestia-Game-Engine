//
// Created by David Price on 16/05/2020.
//

#ifndef HESTIA_ROGUELIKE_DEPENDS_HGE_MATHS_VECTOR_H
#define HESTIA_ROGUELIKE_DEPENDS_HGE_MATHS_VECTOR_H

#include <array>

namespace HGE {

    /**
     * Vector 2 Templated Class
     * @tparam T
     */
    template<typename T>
    struct Vector2 {
        T x, y;

        /* Constructors */
        Vector2() : x(0), y(0) { }
        Vector2(T x, T y) : x(x), y(y) { }
        explicit Vector2(T xy) : x(xy), y(xy) { }

        /**
         * Methods
         */
        void setXY(const T nx, const T ny) {
            this->x = nx;
            this->y = ny;
        }

        [[nodiscard]]
        T magnitude() const {
            return sqrt((x * x) + (y * y));
        }

        [[nodiscard]]
        Vector2 normalised() const {
            return { this->x/magnitude(), this->y/magnitude() };
        }

        std::array<T, 2> asArray() {
            return {x, y};
        }

        /**
         * operators
         */
         template<class U>
        Vector2& operator=(const Vector2<U>& other) {
            this->x = other.x;
            this->y = other.y;
            return *this;
        }

        Vector2 operator-(const Vector2& other) {
            return { this->x - other.x, this->y - other.y };
        }

        Vector2 operator+(const Vector2& other) const {
            return { this->x + other.x, this->y + other.y };
        }

        Vector2& operator+=(const Vector2& other) {
            this->x += other.x;
            this->y += other.y;
            return *this;
        }

        Vector2 operator*(const float value) const {
            return { this->x * value, this->y * value };
        }

        Vector2 operator/(const float value) const {
            return Vector2<T>(this->x / value, this->y / value);
        }

        const Vector2& operator-=(const Vector2& other) {
            this->x -= other.x;
            this->y -= other.y;
            return *this;
        }

        bool operator==(const Vector2& other) const {
            return this->x == other.x && this->y == other.y;
        }

        bool operator!=(const Vector2& other) const {
            return this->x != other.x || this->y != other.y;
        }
    };

    /**
     * Vector 3 Templated class
     * @tparam T
     */
    template<typename T>
    struct Vector3 {
        T x, y, z;

        Vector3() : x(0.0f), y(0.0f), z(0.0f) { }
        Vector3(T x, T y, T z) : x(x), y(y), z(z) { }

        std::array<T, 3> asArray() {
            return {x, y, z};
        }
    };

    /**
     * Vector 4 templated class
     * @tparam T
     */
    template<typename T>
    struct Vector4 {
        T x, y, z, w;

        Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }
        Vector4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) { }

        std::array<T, 4> asArray() {
            return {x, y, z, w};
        }
    };
}

#endif //HESTIA_ROGUELIKE_DEPENDS_HGE_MATHS_VECTOR_H
