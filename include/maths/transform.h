//
// Created by David Price on 16/05/2020.
//

#ifndef HESTIA_ROGUELIKE_DEPENDS_HGE_MATHS_TRANSFORM_H
#define HESTIA_ROGUELIKE_DEPENDS_HGE_MATHS_TRANSFORM_H

namespace HGE {

    template<typename V, typename T>
    struct Transform {
        V mLocalPosition;
        V mScale;
        T mRotation;

        Transform() : mLocalPosition(V()),
                      mScale(1.0f),
                      mRotation(0.0f) {}

        Transform(V localPosition, T rotation, T scale)
            : mLocalPosition(localPosition),
              mScale(scale),
              mRotation(rotation) {}

        Transform(V localPosition, T rotation, T scaleX, T scaleY)
            : mLocalPosition(localPosition),
              mScale(scaleX, scaleY),
              mRotation(rotation) {}
    };
}// namespace HGE

#endif//HESTIA_ROGUELIKE_DEPENDS_HGE_MATHS_TRANSFORM_H
