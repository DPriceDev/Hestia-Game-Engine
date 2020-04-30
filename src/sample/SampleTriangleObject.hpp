#ifndef SAMPLE_TRIANGLE_OBJECT_HPP
#define SAMPLE_TRIANGLE_OBJECT_HPP

#include <iostream>
#include <vector>
#include <functional>

#include "math.h"

#include "../src/framework/ecs/Object.hpp"
#include "../src/framework/graphics/SpriteComponent.hpp"

#include "../util/Logger.hpp"

class SampleTriangleObject : public HGE::Object {

    private:
    HGE::SpriteComponent* mSpriteComponent;

    float mCurrentAngle;

    public:
    void onCreate() override {
        mSpriteComponent = new HGE::SpriteComponent();

        mSpriteComponent->mLocalPosition.x = 25.0f;
        mSpriteComponent->mLocalPosition.y = 25.0f;

        mSpriteComponent->mShader = new HGE::Shader("./assets/shaders/basicSpriteVertexShader.vs", "./assets/shaders/fragmentShader.fs");
 
        registerComponent(mSpriteComponent);
    }

    void tick(double deltaTime) override {
        mCurrentAngle += 6.28 * deltaTime;

        // mSpriteComponent->mVertices[0].x = -0.5 + (0.1 * cos(mCurrentAngle));
        // mSpriteComponent->mVertices[0].y = -0.5 + (0.1 * sin(mCurrentAngle));

        // mSpriteComponent->mVertices[1].x = 0.5 - (0.1 * cos(mCurrentAngle + 1.57));
        // mSpriteComponent->mVertices[1].y = -0.5 + (0.1 * sin(mCurrentAngle + 1.57));

        // mSpriteComponent->mVertices[2].x = 0 + (0.1 * cos(mCurrentAngle + 3.14));
        // mSpriteComponent->mVertices[2].y = 0.5 - (0.1 * sin(mCurrentAngle + 3.14));

        // mSpriteComponent->mVertices[3].x = -0.5 + (0.1 * cos(mCurrentAngle + 4.71));
        // mSpriteComponent->mVertices[3].y = 0.5 - (0.1 * sin(mCurrentAngle + 4.71));
    }
};

#endif