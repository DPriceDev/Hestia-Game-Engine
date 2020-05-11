#ifndef HESTIA_FRAMEWORK_ENGINE_H
#define HESTIA_FRAMEWORK_ENGINE_H

#include <memory>

#include "exceptions.h"

#include "ecs/SystemManager.h"
#include "ecs/ComponentManager.h"
#include "ecs/ObjectManager.h"

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
        std::unique_ptr<GameEnvironment> mCurrentGameEnvironment;

        double mCurrentTickTime;

        Engine() : mCurrentTickTime(0.0) {
            mSystemManager = std::make_unique<SystemManager>();
            mComponentManager = std::make_unique<ComponentManager>();
            mObjectManager = std::make_unique<ObjectManager>();
            mInputManager = std::make_unique<InputManager>();

            mComponentManager->setSystemManager(mSystemManager.get());
        }

        public:
        static Engine* instance() {
            static auto* sEngine = new Engine();
            return sEngine;
        }

        template <class GM>
        void useGraphicsModule() {
            mGraphicsModule = std::make_unique<GM>();
            if(!mGraphicsModule->init()) {
                throw GraphicModuleInitException();
            }
        }

        template <class GE>
        void loadGameEnvironment() {
            mCurrentGameEnvironment = std::make_unique<GE>();

            mCurrentGameEnvironment->beginGame();
            auto lastTime = graphicsModule()->getGameTime();

            while(mGraphicsModule->isWindowOpen()) {
                mCurrentTickTime = graphicsModule()->getGameTime() - lastTime;
                lastTime = graphicsModule()->getGameTime();
                mCurrentGameEnvironment->gameLoop();
                mGraphicsModule->startFrame();
                mSystemManager->run();
                mGraphicsModule->renderFrame();
            }

            mCurrentGameEnvironment->endGame();
        }

        static ObjectManager* objectManager() {
            return instance()->mObjectManager.get();
        }

        static ComponentManager* componentManager() {
            return instance()->mComponentManager.get();
        }

        static SystemManager* systemManager() {
            return instance()->mSystemManager.get();
        }

        static GraphicsModule* graphicsModule() {
            return instance()->mGraphicsModule.get();
        }

        static InputManager* inputManager() {
            return instance()->mInputManager.get();
        }

        static double& tickTime() {
            return instance()->mCurrentTickTime;
        }

        ~Engine() {
            if(mGraphicsModule != nullptr) {
                mGraphicsModule->terminate();
            }
        }
    };
}

#endif