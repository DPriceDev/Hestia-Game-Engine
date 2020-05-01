#ifndef HESTIA_FRAMEWORK_ENGINE_H_
#define HESTIA_FRAMEWORK_ENGINE_H_

#include "ecs/SystemManager.hpp"
#include "ecs/ComponentManager.hpp"
#include "ecs/ObjectManager.hpp"

#include "graphics/GraphicsModule.hpp"

#include "framework/graphics/GraphicsSystem.hpp"
namespace HGE {

    class Engine {
        
        private:
        static Engine* mEngine;
        GraphicsModule* mGraphicsModule;

        SystemManager* mSystemManager;
        ComponentManager* mComponentManager;
        ObjectManager* mObjectManager;
        
        /* Private Constructor */
        Engine() {
            mSystemManager = new SystemManager();
            mComponentManager = new ComponentManager();
            mObjectManager = new ObjectManager();
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

        bool Init(GraphicsModule* graphicsModule);

        void terminate() {
            mGraphicsModule->terminate();
        }

        ObjectManager* getObjectManager() {
            return mObjectManager;
        }

        ComponentManager* getComponentManager() {
            return mComponentManager;
        }

        SystemManager* getSystemManager() {
            return mSystemManager;
        }

        GraphicsModule* getGraphicsModule() {
            return mGraphicsModule;
        }

        ~Engine() { 
            delete mEngine;
            delete mSystemManager;
            delete mComponentManager;
            delete mObjectManager;
            delete mGraphicsModule;
        }
    };
}

#endif