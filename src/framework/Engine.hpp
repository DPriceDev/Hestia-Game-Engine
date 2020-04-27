#ifndef HESTIA_FRAMEWORK_ENGINE_H_
#define HESTIA_FRAMEWORK_ENGINE_H_

#include "ecs/SystemManager.hpp"
#include "ecs/ComponentManager.hpp"
#include "ecs/ObjectManager.hpp"

#include "../src/graphics/GraphicsModule.hpp"

#include "../src/framework/graphics/GraphicsSystem.hpp"

/**
 * Engine Class
 * Provides a static singletion
 */
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
    }
};

#endif