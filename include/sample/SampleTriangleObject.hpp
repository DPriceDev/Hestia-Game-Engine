#ifndef SAMPLE_TRIANGLE_OBJECT_HPP
#define SAMPLE_TRIANGLE_OBJECT_HPP

#include <iostream>
#include <vector>
#include <functional>
#include <memory>

#include "math.h"

#include "framework/Engine.hpp"
#include "framework/ecs/Object.hpp"
#include "framework/sprite/SpriteComponent.hpp"
#include "maths/HGEMath.hpp"

#include "util/Logger.hpp"

class SampleTriangleObject : public HGE::Object {

    private:
    std::unique_ptr<HGE::SpriteComponent> mSpriteComponent;

    float rotation;

    float initialX, initialY;

    public:
    void onCreate() override {
        mSpriteComponent = std::make_unique<HGE::SpriteComponent>();

        HGE::randomFloatBetween(initialX, 100.0f, 700.0f);
        HGE::randomFloatBetween(initialY, 100.0f, 500.0f);

        HGE::randomFloatBetween(rotation, 0.0f, 6.28f);

        mSpriteComponent->mTransform.mLocalPosition.x = initialX;
        mSpriteComponent->mTransform.mLocalPosition.y = initialY;
        HGE::randomFloatBetween(mSpriteComponent->mTransform.mScale.x, 20.0f, 40.0f);
        HGE::randomFloatBetween(mSpriteComponent->mTransform.mScale.y, 20.0f, 40.0f);

        mSpriteComponent->mShader = HGE::Engine::getInstance()
                ->getGraphicsModule()
                ->getShader("./assets/shaders/basicSpriteVertexShader.vs",
                            "./assets/shaders/fragmentShader.fs");
 
        registerComponent(mSpriteComponent.get());
    }

    void tick(double deltaTime) override {

        mSpriteComponent->mTransform.mRotation += 360/3 * deltaTime;

        rotation += 6.28 * deltaTime;

        mSpriteComponent->mTransform.mLocalPosition.x = initialX + (50.0f * sin(rotation));
        mSpriteComponent->mTransform.mLocalPosition.y = initialY + (50.0f * cos(rotation));
    }
};

#endif