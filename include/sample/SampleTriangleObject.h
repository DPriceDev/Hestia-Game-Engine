#ifndef SAMPLE_TRIANGLE_OBJECT_H
#define SAMPLE_TRIANGLE_OBJECT_H

#include <iostream>
#include <vector>
#include <functional>
#include <memory>

#include "math.h"

#include "framework/Engine.h"
#include "framework/ecs/Object.h"
#include "framework/systems/SpriteSystem.h"
#include "framework/systems/ControlSystem.h"
#include "framework/systems/WorldPositionSystem.h"

#include "input/InputTypes.h"

#include "maths/HGEMath.h"
#include "maths/MathsTypes.h"

#include "util/Logger.h"

class SampleTriangleObject : public HGE::Object {

    private:
    HGE::SpriteComponent* mSpriteComponent;
    HGE::ControlComponent* mControlComponent;
    HGE::WorldPositionComponent* mPositionComponent;

    float mMovementSpeed = 220;

    public:
    void onCreate() override {
        mPositionComponent = HGE::Engine::instance()->componentManager()->createComponent<HGE::WorldPositionComponent>(getId());
        mSpriteComponent = HGE::Engine::instance()->componentManager()->createComponent<HGE::SpriteComponent>(getId());

        mPositionComponent->mTransform.mLocalPosition.x = 400;
        mPositionComponent->mTransform.mLocalPosition.y = 300;
        mSpriteComponent->mTransform.mScale.x = 100;
        mSpriteComponent->mTransform.mScale.y = mSpriteComponent->mTransform.mScale.x;

        mSpriteComponent->mShader = HGE::Engine::instance()->graphicsModule()->getShader("./assets/shaders/basicSpriteVertexShader.vs",
                            "./assets/shaders/fragmentShader.fs");

        mSpriteComponent->mMaterial = HGE::Engine::instance()->graphicsModule()->getMaterial("./assets/textures/smileyFace.png");

        mControlComponent = HGE::Engine::instance()->componentManager()->createComponent<HGE::ControlComponent>(getId());
        mControlComponent->addKey(HGE::UP_ARROW_KEY);
        mControlComponent->addKey(HGE::DOWN_ARROW_KEY);
        mControlComponent->addKey(HGE::LEFT_ARROW_KEY);
        mControlComponent->addKey(HGE::RIGHT_ARROW_KEY);
        HGE::Logger::instance()->logDebug("Sample Game Object", "Created!");
    }

    void tick(double deltaTime) override {
        mSpriteComponent->mTransform.mRotation += 360/3 * deltaTime;

        if(mControlComponent->getKeyValue(HGE::UP_ARROW_KEY)) {
            mPositionComponent->mTransform.mLocalPosition.y += mMovementSpeed * deltaTime;
        }

        if(mControlComponent->getKeyValue(HGE::DOWN_ARROW_KEY)) {
            mPositionComponent->mTransform.mLocalPosition.y -= mMovementSpeed * deltaTime;
        }

        if(mControlComponent->getKeyValue(HGE::LEFT_ARROW_KEY)) {
            mPositionComponent->mTransform.mLocalPosition.x -= mMovementSpeed * deltaTime;
        }

        if(mControlComponent->getKeyValue(HGE::RIGHT_ARROW_KEY)) {
            mPositionComponent->mTransform.mLocalPosition.x += mMovementSpeed * deltaTime;
        }
    }
};

#endif