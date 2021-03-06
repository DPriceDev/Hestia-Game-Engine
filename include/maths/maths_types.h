#ifndef HESTIA_FRAMEWORK_MATHS_MATHSTYPES_H
#define HESTIA_FRAMEWORK_MATHS_MATHSTYPES_H

#include <array>
#include <iostream>

#include <grid.h>
#include <grid_view.h>
#include <rect.h>
#include <vector.h>

#include "transform.h"

namespace HGE {
    using Pointf = float;
    using Pointi = int;
    using Pointd = double;
    using Rotf = float;
    using Scalef = float;

    using Vector2f = ATA::Vector2<Pointf>;
    using Vector3f = ATA::Vector3<Pointf>;
    using Vector2i = ATA::Vector2<Pointi>;
    using Vector2d = ATA::Vector2<Pointd>;

    template<class Type>
    using Grid = ATA::Grid2D<Type>;
    template<class Type>
    using GridView = ATA::GridView<Type>;

    using Transform2f = Transform<Vector2f, Pointf>;

    using Rectf = ATA::Rect<float>;
    using Recti = ATA::Rect<int>;

    using ColourRGB = ATA::Vector3<Pointf>;
    using ColourRGBA = ATA::Vector4<Pointf>;
}// namespace HGE

#endif