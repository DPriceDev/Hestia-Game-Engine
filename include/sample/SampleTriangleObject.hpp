#ifndef SAMPLE_TRIANGLE_OBJECT_HPP
#define SAMPLE_TRIANGLE_OBJECT_HPP

#include <iostream>
#include <vector>
#include <functional>
#include <memory>

#include "math.h"

#include "framework/Engine.hpp"
#include "framework/ecs/ecs.h"
#include "framework/systems/SpriteSystem.hpp"
#include "framework/systems/ControlSystem.hpp"
#include "framework/systems/WorldPositionSystem.h"

#include "input/InputTypes.hpp"

#include "maths/HGEMath.hpp"
#include "maths/MathsTypes.hpp"

#include "util/Logger.hpp"

class SampleTriangleObject : public HGE::Object {

    private:
    HGE::SpriteComponent* mSpriteComponent;
    HGE::ControlComponent* mControlComponent;
    HGE::WorldPositionComponent* mPositionComponent;

    float mMovementSpeed = 220;

    public:
    void onCreate() override {
        mPositionComponent = HGE::Engine::getInstance()->getComponentManager()->createComponent<HGE::WorldPositionComponent>(id);
        mSpriteComponent = HGE::Engine::getInstance()->getComponentManager()->createComponent<HGE::SpriteComponent>(id);

        mSpriteComponent->mTransform.mLocalPosition.x = 400;
        mSpriteComponent->mTransform.mLocalPosition.y = 300;
        mSpriteComponent->mTransform.mScale.x = 100;
        mSpriteComponent->mTransform.mScale.y = mSpriteComponent->mTransform.mScale.x;

        mSpriteComponent->mShader = HGE::Engine::getInstance()->getGraphicsModule()->getShader("./assets/shaders/basicSpriteVertexShader.vs",
                            "./assets/shaders/fragmentShader.fs");

        mSpriteComponent->mMaterial = HGE::Engine::getInstance()->getGraphicsModule()->getMaterial("./assets/textures/smileyFace.png");

        mControlComponent = HGE::Engine::getInstance()->getComponentManager()->createComponent<HGE::ControlComponent>(id);
        mControlComponent->addKey(HGE::UP_ARROW_KEY);
        mControlComponent->addKey(HGE::DOWN_ARROW_KEY);
        mControlComponent->addKey(HGE::LEFT_ARROW_KEY);
        mControlComponent->addKey(HGE::RIGHT_ARROW_KEY);
        HGE::Logger::getInstance()->logDebug("Sample Game Object", "Created!");
    }

    void tick(double deltaTime) override {
        mSpriteComponent->mTransform.mRotation += 360/3 * deltaTime;

        if(mControlComponent->getKeyValue(HGE::UP_ARROW_KEY)) {
            mSpriteComponent->mTransform.mLocalPosition.y += mMovementSpeed * deltaTime;
        }

        if(mControlComponent->getKeyValue(HGE::DOWN_ARROW_KEY)) {
            mSpriteComponent->mTransform.mLocalPosition.y -= mMovementSpeed * deltaTime;
        }

        if(mControlComponent->getKeyValue(HGE::LEFT_ARROW_KEY)) {
            mSpriteComponent->mTransform.mLocalPosition.x -= mMovementSpeed * deltaTime;
        }

        if(mControlComponent->getKeyValue(HGE::RIGHT_ARROW_KEY)) {
            mSpriteComponent->mTransform.mLocalPosition.x += mMovementSpeed * deltaTime;
        }
    }
};

#endif