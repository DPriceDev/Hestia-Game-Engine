//
// Created by David Price on 28/05/2020.
//

#include "catch.hpp"
#include "maths/maths.h"

TEST_CASE("Test random number generator") {
    using namespace HGE;

    auto randomInt = randomNumberBetween(0, 10);
//    auto randomfloat = randomNumberBetween(0.0f, 10.0f);
//    auto randomDouble = randomNumberBetween(0.0, 10.0);

    CHECK(randomInt >= 0);
    CHECK(randomInt <= 10);
//    CHECK(randomfloat >= 0.0f);
//    CHECK(randomfloat <= 10.0f);
//    CHECK(randomDouble >= 0.0);
//    CHECK(randomDouble <= 10.0);

    auto randomNegativeInt = randomNumberBetween(-10, -4);
//    auto randomNegativefloat = randomNumberBetween(-12.5f, -3.2f);
//    auto randomNegativeDouble = randomNumberBetween(-1000.0, -9.0);

    CHECK(randomNegativeInt <= -4);
    CHECK(randomNegativeInt >= -10);
//    CHECK(randomNegativefloat <= -3.2f);
//    CHECK(randomNegativefloat >= -12.5f);
//    CHECK(randomNegativeDouble <= -9.0);
//    CHECK(randomNegativeDouble >= -1000.0);

    // TODO: Add check for maximum and minimum swapped
}

TEST_CASE("Test Rounding Value to a specific multiplier function") {
    using namespace HGE;

    auto roundFloatToOne = roundValueToMultipleOf(123.23f, 1.0f);
    auto roundFloatToThirtyTwo = roundValueToMultipleOf(146.0f, 32.0f);

    CHECK(roundFloatToOne == 123.0f);
    CHECK(roundFloatToThirtyTwo == 160.0f);

    auto roundNegativeFloatToOne = roundValueToMultipleOf(-123.23f, 1.0f);
    auto roundNegativeFloatToThirtyTwo = roundValueToMultipleOf(-146.0f, 32.0f);

    CHECK(roundNegativeFloatToOne == -124.0f);
    CHECK(roundNegativeFloatToThirtyTwo == -128.0f);

    //TODO: should it ceil negative?
    // TODO: Check for negative multiple?
}

TEST_CASE("Test Ceiling to a specific type") {
    using namespace HGE;

    int floatToInt = ceilToType<int>(32.5f);
    int floatTofloat = ceilToType<int>(34.6f);

    CHECK(floatToInt == 33);
    CHECK(floatTofloat == 35.0f);
}

TEST_CASE("Test If a point is in a circle") {
    using namespace HGE;

    auto testCircleRadius = 32.0f;
    auto testCircleCenter = Vector2f(0.0f, 0.0f);

    auto pointInCircle = Vector2f(4.0f, 12.0f);
    auto pointOutOfCircle = Vector2f(32.0, 32.0);
    auto pointOnCircleEdge = Vector2f(0.0f, 32.0f);

    CHECK(isPointInACircle(pointInCircle, testCircleCenter, testCircleRadius));
    CHECK(!isPointInACircle(pointOutOfCircle, testCircleCenter, testCircleRadius));
    CHECK(isPointInACircle(pointOnCircleEdge, testCircleCenter, testCircleRadius));
}