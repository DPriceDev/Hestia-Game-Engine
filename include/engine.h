#ifndef HESTIA_FRAMEWORK_ENGINE_H
#define HESTIA_FRAMEWORK_ENGINE_H

#include <framework/events/EventManager.h>
#include <memory>

#include "framework/exceptions.h"

#include "context.h"

#include "camera/camera_manager.h"
#include "framework/ecs/component_array_container.h"
#include "framework/ecs/object_manager.h"
#include "framework/ecs/system_manager.h"

#include "game/game_envrionment.h"

#include "graphics/graphics_module.h"
#include "input/input_manager.h"

namespace HGE {

    class Engine {
        std::unique_ptr<GraphicsModule> mGraphicsModule;

        std::unique_ptr<Context> mContext;
        std::unique_ptr<SystemManager> mSystemManager;
        std::unique_ptr<ComponentArrayContainer> mComponentManager;
        std::unique_ptr<ObjectManager> mObjectManager;
        std::unique_ptr<InputManager> mInputManager;
        std::unique_ptr<CameraManager> mCameraManager;
        std::unique_ptr<EventManager> mEventManager;

        std::unique_ptr<GameEnvironment> mCurrentGameEnvironment;

        double mCurrentTickTime;

    public:
        Engine() : mCurrentTickTime(0.0),
                   mContext(std::make_unique<Context>()),
                   mSystemManager(std::make_unique<SystemManager>()),
                   mComponentManager(std::make_unique<ComponentArrayContainer>()),
                   mObjectManager(std::make_unique<ObjectManager>(mContext.get())),
                   mGraphicsModule(nullptr),
                   mInputManager(nullptr),
                   mEventManager(std::make_unique<EventManager>()),
                   mCurrentGameEnvironment(nullptr) {
            mContext->mComponentManager = this->mComponentManager.get();
            mContext->mSystemManager = this->mSystemManager.get();
            mContext->mObjectManager = this->mObjectManager.get();
        }

        template<typename GM>
        void useGraphicsModule() {
            mGraphicsModule = std::make_unique<GM>();
            if (!mGraphicsModule->init()) {
                throw GraphicModuleInitException();
            }
            mCameraManager = std::make_unique<CameraManager>(mGraphicsModule.get());
            mInputManager = std::make_unique<InputManager>(mGraphicsModule.get());

            mContext->mInputManager = mInputManager.get();
            mContext->mGraphicsModule = mGraphicsModule.get();
            mContext->mCameraManager = mCameraManager.get();
        }

        template<typename GE>
        void loadGameEnvironment() {
            auto gameEnvironment = std::make_unique<GE>(mContext.get());
            mCurrentGameEnvironment = std::move(gameEnvironment);

            mCurrentGameEnvironment->beginGame();
            auto lastTime = getGraphicsModule()->getGameTime();

            while (mGraphicsModule->isWindowOpen()) {
                mCurrentTickTime = mGraphicsModule->getGameTime() - lastTime;
                lastTime = mGraphicsModule->getGameTime();

                mCurrentGameEnvironment->gameLoop(mCurrentTickTime);
                mGraphicsModule->startFrame();
                mSystemManager->run(mCurrentTickTime);
                mGraphicsModule->renderFrame();
            }

            mCurrentGameEnvironment->endGame();
        }

        GraphicsModule *getGraphicsModule() {
            return mGraphicsModule.get();
        }

        ~Engine() {
            if (mGraphicsModule != nullptr) {
                mGraphicsModule->terminate();
            }
        }
    };
}// namespace HGE

#endif