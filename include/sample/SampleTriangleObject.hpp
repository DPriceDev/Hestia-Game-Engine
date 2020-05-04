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
#include "framework/input/InputComponent.hpp"

#include "input/InputTypes.hpp"

#include "maths/HGEMath.hpp"
#include "maths/MathsTypes.hpp"

#include "util/Logger.hpp"

class SampleTriangleObject : public HGE::Object {

    private:
    std::unique_ptr<HGE::SpriteComponent> mSpriteComponent;
    std::unique_ptr<HGE::InputComponent> mInputComponent;

    float mMovementSpeed = 220;

    public:
    void onCreate() override {
        mSpriteComponent = std::make_unique<HGE::SpriteComponent>();


        mSpriteComponent->mTransform.mLocalPosition.x = 400;
        mSpriteComponent->mTransform.mLocalPosition.y = 300;
        mSpriteComponent->mTransform.mScale.x = 100;
        mSpriteComponent->mTransform.mScale.y = mSpriteComponent->mTransform.mScale.x;

        mSpriteComponent->mShader = HGE::Engine::getInstance()->getGraphicsModule()->getShader("./assets/shaders/basicSpriteVertexShader.vs",
                            "./assets/shaders/fragmentShader.fs");

        mSpriteComponent->mMaterial = HGE::Engine::getInstance()->getGraphicsModule()->getMaterial("./assets/textures/smileyFace.png");

        registerComponent(mSpriteComponent.get());

        mInputComponent = std::make_unique<HGE::InputComponent>();

        mInputComponent->addKey(HGE::UP_ARROW_KEY);
        mInputComponent->addKey(HGE::DOWN_ARROW_KEY);
        mInputComponent->addKey(HGE::LEFT_ARROW_KEY);
        mInputComponent->addKey(HGE::RIGHT_ARROW_KEY);

        registerComponent(mInputComponent.get());
    }

    void tick(double deltaTime) override {
        mSpriteComponent->mTransform.mRotation += 360/3 * deltaTime;

        if(mInputComponent->getKeyValue(HGE::UP_ARROW_KEY)) {
            mSpriteComponent->mTransform.mLocalPosition.y += mMovementSpeed * deltaTime;
        }

        if(mInputComponent->getKeyValue(HGE::DOWN_ARROW_KEY)) {
            mSpriteComponent->mTransform.mLocalPosition.y -= mMovementSpeed * deltaTime;
        }

        if(mInputComponent->getKeyValue(HGE::LEFT_ARROW_KEY)) {
            mSpriteComponent->mTransform.mLocalPosition.x -= mMovementSpeed * deltaTime;
        }

        if(mInputComponent->getKeyValue(HGE::RIGHT_ARROW_KEY)) {
            mSpriteComponent->mTransform.mLocalPosition.x += mMovementSpeed * deltaTime;
        }
    }
};

#endif