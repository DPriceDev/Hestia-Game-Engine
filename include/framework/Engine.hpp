#ifndef HESTIA_FRAMEWORK_ENGINE_H_
#define HESTIA_FRAMEWORK_ENGINE_H_

#include <memory>

#include "ecs/SystemManager.hpp"
#include "ecs/ComponentManager.hpp"
#include "ecs/ObjectManager.hpp"

#include "graphics/GraphicsModule.hpp"
#include "input/InputManager.hpp"

namespace HGE {
    class Engine {
        
        static Engine* mEngine;
        std::unique_ptr<GraphicsModule> mGraphicsModule;

        std::unique_ptr<SystemManager> mSystemManager;
        std::unique_ptr<ComponentManager> mComponentManager;
        std::unique_ptr<ObjectManager> mObjectManager;
        std::unique_ptr<InputManager> mInputManager;
        
        /* Private Constructor */
        Engine() {
            mSystemManager = std::make_unique<SystemManager>();
            mComponentManager = std::make_unique<ComponentManager>();
            mComponentManager->setSystemManager(mSystemManager.get());

            mObjectManager = std::make_unique<ObjectManager>();
            mInputManager = std::make_unique<InputManager>();
        }

        public:
        static Engine* getInstance() {
            if(!mEngine) {
                mEngine = new Engine();
            }
            return mEngine;
        }

        bool Init(std::unique_ptr<GraphicsModule> graphicsModule);

        void terminate() {
            mGraphicsModule->terminate();
        }

        ObjectManager* getObjectManager() {
            return mObjectManager.get();
        }

        ComponentManager* getComponentManager() {
            return mComponentManager.get();
        }

        SystemManager* getSystemManager() {
            return mSystemManager.get();
        }

        GraphicsModule* getGraphicsModule() {
            return mGraphicsModule.get();
        }

        InputManager* getInputManager() {
            return mInputManager.get();
        }

        ~Engine() { 
            delete mEngine;
        }
    };
}

#endif