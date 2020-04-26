#ifndef HESTIA_FRAMEWORK_ENGINE_H_
#define HESTIA_FRAMEWORK_ENGINE_H_

#include "systems/SystemManager.hpp"
#include "components/ComponentManager.hpp"
#include "objects/ObjectManager.hpp"

#include "../graphics/GraphicsSystem.hpp"

/**
 * Engine Class
 * Provides a static singletion
 */
class Engine {
    
    private:
    /* Private Variables */
    static Engine* mEngine;

    SystemManager* mSystemManager;
    ComponentManager* mComponentManager;
    ObjectManager* mObjectManager;
    
    /* Private Constructor */
    Engine() {
        mSystemManager = new SystemManager();
        mComponentManager = new ComponentManager();
        mObjectManager = new ObjectManager();

        //mSystemManager->registerSystem<GraphicsSystem>();
    }

    public:
    static Engine* getInstance() {
        if(!mEngine) {
            mEngine = new Engine();
        }
        return mEngine;
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

    ~Engine() { 
        delete mEngine;
        delete mSystemManager;
        delete mComponentManager;
        delete mObjectManager;
    }
};

#endif