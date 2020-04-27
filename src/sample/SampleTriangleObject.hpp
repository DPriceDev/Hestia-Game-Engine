#ifndef SAMPLE_TRIANGLE_OBJECT_HPP
#define SAMPLE_TRIANGLE_OBJECT_HPP

#include <iostream>
#include <vector>
#include <functional>

#include "math.h"

#include "../src/framework/ecs/Object.hpp"
#include "../src/framework/graphics/GraphicsComponent.hpp"
#include "../src/framework/tick/TickComponent.hpp"

#include "../util/Logger.hpp"

/**
 * 
 */
class SampleTriangleObject : public Object {

    private:
    GraphicsComponent* mGraphicsComponent;

    float mCurrentAngle;

    public:
    SampleTriangleObject() { }

    ~SampleTriangleObject() {

    }

    void onCreate() override {
        mGraphicsComponent = new GraphicsComponent();

        mGraphicsComponent->mVertices.push_back(Vector2f(-0.5, -0.5));
        mGraphicsComponent->mVertices.push_back(Vector2f(0.5, -0.5));
        mGraphicsComponent->mVertices.push_back(Vector2f(0.0, 0.5));

        mGraphicsComponent->mShader = new Shader("vertexShader.vs", "fragmentShader.fs");

        registerComponent(mGraphicsComponent);
    }

    void tick(float deltaTime) {

        mCurrentAngle += 6.28 * (deltaTime/1000);

        mGraphicsComponent->mVertices[0].x = -0.5 + (0.1 * cos(mCurrentAngle));
        mGraphicsComponent->mVertices[0].y = -0.5 + (0.1 * sin(mCurrentAngle));

        mGraphicsComponent->mVertices[1].x = 0.5 - (0.1 * cos(mCurrentAngle + 2.09));
        mGraphicsComponent->mVertices[1].y = -0.5 + (0.1 * sin(mCurrentAngle + 2.09));

        mGraphicsComponent->mVertices[2].x = 0.0 + (0.1 * cos(mCurrentAngle + 4.18));
        mGraphicsComponent->mVertices[2].y = 0.5 - (0.1 * sin(mCurrentAngle + 4.18));
    }
};

#endif