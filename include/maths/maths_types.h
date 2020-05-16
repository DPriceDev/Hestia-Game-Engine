#ifndef HESTIA_FRAMEWORK_MATHS_MATHSTYPES_H
#define HESTIA_FRAMEWORK_MATHS_MATHSTYPES_H

#include <array>
#include <iostream>
#include "vector.h"
#include "transform.h"
#include "rect.h"

namespace HGE {
    using Pointf = float;
    using Pointi = int;
    using Pointd = double;
    using Rotf = float;
    using Scalef = float;

    using Vector2f = Vector2<Pointf>;
    using Vector2i = Vector2<Pointi>;
    using Vector2d = Vector2<Pointd>;

    using Transform2f = Transform<Vector2f, Pointf>;

    using Rectf = Rect<Vector2f>;

    using ColourRGB = Vector3<Pointf>;
    using ColourRGBA = Vector4<Pointf>;
}

#endif