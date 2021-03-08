//
// Created by David Price on 28/05/2020.
//

#include "catch2/catch.hpp"
#include "maths/maths_types.h"
#include "maths/transform.h"

TEST_CASE("Test default transform data is constructed correctly") {
    using namespace HGE;
    auto defaultFloatTransform = Transform<Vector2f, Pointf>();
    auto defaultIntTransform = Transform<Vector2i, Pointi>();

    CHECK(defaultFloatTransform.mLocalPosition == Vector2f(0.0f, 0.0f));
    CHECK(defaultIntTransform.mLocalPosition == Vector2i(0, 0));
    CHECK(defaultFloatTransform.mScale == Vector2f(1.0f, 1.0f));
    CHECK(defaultIntTransform.mScale == Vector2i(1, 1));
    CHECK(defaultFloatTransform.mRotation == 0.0f);
    CHECK(defaultIntTransform.mRotation == 0);
}

TEST_CASE("Test specified constructor transform data is constructed correctly") {
    using namespace HGE;
    auto floatTransform = Transform(Vector2f(50.0f, 50.0f), 32.4f, 5.0f);
    auto intTransform = Transform(Vector2i(20, -50), -29, 3);

    CHECK(floatTransform.mLocalPosition == Vector2f(50.0f, 50.0f));
    CHECK(intTransform.mLocalPosition == Vector2i(20, -50));
    CHECK(floatTransform.mScale == Vector2f(5.0f, 5.0f));
    CHECK(intTransform.mScale == Vector2i(3, 3));
    CHECK(floatTransform.mRotation == 32.4f);
    CHECK(intTransform.mRotation == -29);
}

TEST_CASE("Test specified constructor with scale transform data is constructed correctly") {
    using namespace HGE;
    auto floatTransform = Transform(Vector2f(50.0f, 50.0f), 32.4f, 5.0f, 4.0f);
    auto intTransform = Transform(Vector2i(20, -50), -29, 3, 2);

    CHECK(floatTransform.mLocalPosition == Vector2f(50.0f, 50.0f));
    CHECK(intTransform.mLocalPosition == Vector2i(20, -50));
    CHECK(floatTransform.mScale == Vector2f(5.0f, 4.0f));
    CHECK(intTransform.mScale == Vector2i(3, 2));
    CHECK(floatTransform.mRotation == 32.4f);
    CHECK(intTransform.mRotation == -29);
}