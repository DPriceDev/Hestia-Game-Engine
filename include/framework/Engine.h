#ifndef HESTIA_FRAMEWORK_ENGINE_H
#define HESTIA_FRAMEWORK_ENGINE_H

#include <memory>

#include "exceptions.h"

#include "ecs/SystemManager.h"
#include "ecs/ComponentManager.h"
#include "ecs/ObjectManager.h"
#include "camera/CameraManager.h"

#include "GameEnvironment.h"

#include "graphics/GraphicsModule.h"
#include "input/InputManager.h"

namespace HGE {

    class Engine {
        std::unique_ptr<GraphicsModule> mGraphicsModule;

        std::unique_ptr<SystemManager> mSystemManager;
        std::unique_ptr<ComponentManager> mComponentManager;
        std::unique_ptr<ObjectManager> mObjectManager;
        std::unique_ptr<InputManager> mInputManager;
        std::unique_ptr<CameraManager> mCameraManager;

        std::unique_ptr<GameEnvironment> mCurrentGameEnvironment;

        double mCurrentTickTime;

        template<typename T>
        void initialiseEcsFacade(T* ecsFacade) {
            ecsFacade->mObjectManager = mObjectManager.get();
            ecsFacade->mComponentManager = mComponentManager.get();
        }

        Engine() : mCurrentTickTime(0.0),
                   mSystemManager(std::make_unique<SystemManager>()),
                   mComponentManager(std::make_unique<ComponentManager>(mSystemManager.get())),
                   mObjectManager(std::make_unique<ObjectManager>(mComponentManager.get())),
                   mGraphicsModule(nullptr),
                   mInputManager(nullptr),
                   mCurrentGameEnvironment(nullptr) { }

    public:
        static Engine* instance() {
            static auto* sEngine = new Engine();
            return sEngine;
        }

        template <graphics_module GM>
        static void useGraphicsModule() {
            instance()->mGraphicsModule = std::make_unique<GM>();
            if(!instance()->mGraphicsModule->init()) {
                throw GraphicModuleInitException();
            }
            instance()->mCameraManager = std::make_unique<CameraManager>(graphicsModule());
            instance()->mInputManager = std::make_unique<InputManager>(graphicsModule());
        }

        template <game_environment GE>
        void loadGameEnvironment() {
            auto gameEnvironment = std::make_unique<GE>();
            initialiseEcsFacade<GE>(gameEnvironment.get());
            mCurrentGameEnvironment = std::move(gameEnvironment);

            mCurrentGameEnvironment->beginGame();
            auto lastTime = graphicsModule()->getGameTime();

            while(mGraphicsModule->isWindowOpen()) {
                mCurrentTickTime = graphicsModule()->getGameTime() - lastTime;
                lastTime = graphicsModule()->getGameTime();

                mCurrentGameEnvironment->gameLoop(mCurrentTickTime);
                mGraphicsModule->startFrame();
                mSystemManager->run(mCurrentTickTime);
                mGraphicsModule->renderFrame();
            }

            mCurrentGameEnvironment->endGame();
        }

        static CameraManager* cameraManager() {
            return instance()->mCameraManager.get();
        }

        static ComponentManager* componentManager() {
            return instance()->mComponentManager.get();
        }

        static GraphicsModule* graphicsModule() {
            return instance()->mGraphicsModule.get();
        }

        static InputManager* inputManager() {
            return instance()->mInputManager.get();
        }

        ~Engine() {
            if(mGraphicsModule != nullptr) {
                mGraphicsModule->terminate();
            }
        }
    };
}

#endif