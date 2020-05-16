//
// Created by David Price on 16/05/2020.
//

#ifndef HESTIA_ROGUELIKE_DEPENDS_HGE_MATHS_RECT_H
#define HESTIA_ROGUELIKE_DEPENDS_HGE_MATHS_RECT_H

namespace HGE {

    /**
     * Rect Templated Class
     */
    template<typename V>
    struct Rect {
        V mPosition;
        V mSize;

        Rect(V position, V size) : mPosition(position), mSize(size) { }
        Rect() : mPosition(V()), mSize(V()) { }

        [[nodiscard]]
        V bottomLeft() const {
            return mPosition;
        }

        [[nodiscard]]
        V bottomRight() const {
            return {mPosition.x + mSize.x, mPosition.y};
        }

        [[nodiscard]]
        V topLeft() const {
            return {mPosition.x, mPosition.y + mSize.y};
        }

        [[nodiscard]]
        V topRight() const {
            return {mPosition.x + mSize.x, mPosition.y + mSize.y};
        }

        [[maybe_unused]]
        [[nodiscard]]
        bool isOverlapping(const Rect& other) const {
            if (this->topLeft().x >= other.bottomRight().x
                || other.topLeft().x >= this->bottomRight().x) {
                return false;
            }

            return !(this->topLeft().y <= other.bottomRight().y
                     || other.topLeft().y <= this->bottomRight().y);
        }

        [[maybe_unused]]
        [[nodiscard]]
        V midpoint() const {
            return {mPosition.x + (mSize.x/2.0f), mPosition.y + (mSize.y/2.0f) };
        }
    };
}

#endif //HESTIA_ROGUELIKE_DEPENDS_HGE_INCLUDE_MATHS_RECT_H
