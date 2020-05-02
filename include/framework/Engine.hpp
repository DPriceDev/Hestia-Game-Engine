#ifndef HESTIA_FRAMEWORK_ENGINE_H_
#define HESTIA_FRAMEWORK_ENGINE_H_

#include <memory>

#include "ecs/SystemManager.hpp"
#include "ecs/ComponentManager.hpp"
#include "ecs/ObjectManager.hpp"

#include "graphics/GraphicsModule.hpp"

namespace HGE {
    class Engine {
        
        private:
        static Engine* mEngine;
        std::unique_ptr<GraphicsModule> mGraphicsModule;

        std::unique_ptr<SystemManager> mSystemManager;
        std::unique_ptr<ComponentManager> mComponentManager;
        std::unique_ptr<ObjectManager> mObjectManager;
        
        /* Private Constructor */
        Engine() {
            mSystemManager = std::make_unique<SystemManager>();
            mComponentManager = std::make_unique<ComponentManager>();
            mObjectManager = std::make_unique<ObjectManager>();
        }

        public:
        static Engine* getInstance() {
            if(!mEngine) {
                mEngine = new Engine();
            }
            return mEngine;
        }

        // static ObjectManager* objectManager() {
        //     return mEngine->mObjectManager;
        // }

        // static ComponentManager* componentManager() {
        //     return mEngine->mComponentManager;
        // }

        // static SystemManager* systemManager() {
        //     return mEngine->mSystemManager;
        // }

        // static GraphicsModule* graphicsModule() {
        //     return mEngine->mGraphicsModule;
        // }

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

        ~Engine() { 
            delete mEngine;
        }
    };
}

#endif