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
                      mRotation(0.0f),
                      mScale(1.0f) {}

        Transform(V localPosition, T rotation, T scale)
            : mLocalPosition(localPosition),
              mRotation(rotation),
              mScale(scale) {}

        Transform(V localPosition, T rotation, T scaleX, T scaleY)
            : mLocalPosition(localPosition),
              mRotation(rotation),
              mScale(scaleX, scaleY) {}
    };
}// namespace HGE

#endif//HESTIA_ROGUELIKE_DEPENDS_HGE_MATHS_TRANSFORM_H
