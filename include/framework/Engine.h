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

        Engine() {
            mSystemManager = std::make_unique<SystemManager>();
            mComponentManager = std::make_unique<ComponentManager>();
            mObjectManager = std::make_unique<ObjectManager>();
            mInputManager = std::make_unique<InputManager>();

            mComponentManager->setSystemManager(mSystemManager.get());
        }

        public:
        static Engine* instance() {
            static Engine* engine = new Engine();
            return engine;
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

            while(mGraphicsModule->isWindowOpen()) {
                mCurrentGameEnvironment->gameLoop();
                mObjectManager->tick();
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

        ~Engine() {
            if(mGraphicsModule.get() != nullptr) {
                mGraphicsModule->terminate();
            }
        }
    };
}

#endif