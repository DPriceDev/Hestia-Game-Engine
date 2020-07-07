#ifndef HESTIA_FRAMEWORK_ENGINE_H
#define HESTIA_FRAMEWORK_ENGINE_H

#include <framework/events/EventManager.h>
#include <memory>

#include "framework/exceptions.h"

#include "context.h"

#include "camera/camera_manager.h"
#include "framework/ecs/component_manager.h"
#include "framework/ecs/object_manager.h"
#include "framework/ecs/system_manager.h"

#include "framework/game_envrionment.h"

#include "graphics/graphics_module.h"
#include "input/input_manager.h"

namespace HGE {

    class Engine {
        std::unique_ptr<GraphicsModule> mGraphicsModule;

        std::unique_ptr<Context> mContext;
        std::unique_ptr<SystemManager> mSystemManager;
        std::unique_ptr<ComponentManager> mComponentManager;
        std::unique_ptr<ObjectManager> mObjectManager;
        std::unique_ptr<InputManager> mInputManager;
        std::unique_ptr<CameraManager> mCameraManager;
        std::unique_ptr<EventManager> mEventManager;

        std::unique_ptr<GameEnvironment> mCurrentGameEnvironment;

        double mCurrentTickTime;

        Engine() : mCurrentTickTime(0.0),
                   mContext(std::make_unique<Context>()),
                   mSystemManager(std::make_unique<SystemManager>(mContext.get())),
                   mComponentManager(std::make_unique<ComponentManager>(mContext.get())),
                   mObjectManager(std::make_unique<ObjectManager>(mContext.get())),
                   mGraphicsModule(nullptr),
                   mInputManager(nullptr),
                   mEventManager(std::make_unique<EventManager>()),
                   mCurrentGameEnvironment(nullptr) {
            mContext->mComponentManager = this->mComponentManager.get();
            mContext->mSystemManager = this->mSystemManager.get();
            mContext->mObjectManager = this->mObjectManager.get();
        }

    public:
        static Engine *instance() {
            static auto *sEngine = new Engine();
            return sEngine;
        }

        template<typename GM>
        static void useGraphicsModule() {
            instance()->mGraphicsModule = std::make_unique<GM>();
            if (!instance()->mGraphicsModule->init()) {
                throw GraphicModuleInitException();
            }
            instance()->mCameraManager = std::make_unique<CameraManager>(graphicsModule());
            instance()->mInputManager = std::make_unique<InputManager>(graphicsModule());
        }

        template<typename GE>
        void loadGameEnvironment() {
            auto gameEnvironment = std::make_unique<GE>(mContext.get());
            mCurrentGameEnvironment = std::move(gameEnvironment);

            mCurrentGameEnvironment->beginGame();
            auto lastTime = graphicsModule()->getGameTime();

            while (mGraphicsModule->isWindowOpen()) {
                mCurrentTickTime = graphicsModule()->getGameTime() - lastTime;
                lastTime = graphicsModule()->getGameTime();

                mCurrentGameEnvironment->gameLoop(mCurrentTickTime);
                mGraphicsModule->startFrame();
                mSystemManager->run(mCurrentTickTime);
                mGraphicsModule->renderFrame();
            }

            mCurrentGameEnvironment->endGame();
        }

        static CameraManager *cameraManager() {
            return instance()->mCameraManager.get();
        }

        static ComponentManager *componentManager() {
            return instance()->mComponentManager.get();
        }

        static GraphicsModule *graphicsModule() {
            return instance()->mGraphicsModule.get();
        }

        static InputManager *inputManager() {
            return instance()->mInputManager.get();
        }

        ~Engine() {
            if (mGraphicsModule != nullptr) {
                mGraphicsModule->terminate();
            }
        }
    };
}// namespace HGE

#endif