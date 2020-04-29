#ifndef SAMPLE_TRIANGLE_OBJECT_HPP
#define SAMPLE_TRIANGLE_OBJECT_HPP

#include <iostream>
#include <vector>
#include <functional>

#include "math.h"

#include "../src/framework/ecs/Object.hpp"
#include "../src/framework/graphics/SpriteComponent.hpp"

#include "../util/Logger.hpp"

/**
 * 
 */
class SampleTriangleObject : public Object {

    private:
    SpriteComponent* mSpriteComponent;

    float mCurrentAngle;

    public:
    SampleTriangleObject() { }

    ~SampleTriangleObject() {

    }

    void onCreate() override {
        mSpriteComponent = new SpriteComponent();

        mSpriteComponent->mVertices[0].setXY(0.5, 0.5);
        mSpriteComponent->mVertices[1].setXY(0.5, -0.5);
        mSpriteComponent->mVertices[2].setXY(-0.5, -0.5);
        mSpriteComponent->mVertices[3].setXY(-0.5, 0.5);

        mSpriteComponent->mShader = new Shader("./assets/shaders/vertexShader.vs", "./assets/shaders/fragmentShader.fs");

        registerComponent(mSpriteComponent);
    }

    void tick(float deltaTime) {

        mCurrentAngle += 6.28 * (deltaTime/1000);

        mSpriteComponent->mVertices[0].x = 0.5 + (0.1 * cos(mCurrentAngle));
        mSpriteComponent->mVertices[0].y = 0.5 + (0.1 * sin(mCurrentAngle));

        mSpriteComponent->mVertices[1].x = 0.5 - (0.1 * cos(mCurrentAngle + 1.57));
        mSpriteComponent->mVertices[1].y = -0.5 + (0.1 * sin(mCurrentAngle + 1.57));

        mSpriteComponent->mVertices[2].x = -0.5 + (0.1 * cos(mCurrentAngle + 3.14));
        mSpriteComponent->mVertices[2].y = -0.5 - (0.1 * sin(mCurrentAngle + 3.14));

        mSpriteComponent->mVertices[3].x = -0.5 + (0.1 * cos(mCurrentAngle + 4.71));
        mSpriteComponent->mVertices[3].y = 0.5 - (0.1 * sin(mCurrentAngle + 4.71));
    }
};

#endif