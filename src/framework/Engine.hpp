#ifndef HESTIA_FRAMEWORK_ENGINE_H_
#define HESTIA_FRAMEWORK_ENGINE_H_

#include "glad/glad.h"
#include "GLFW/glfw3.h"

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
    GLFWwindow* mWindow;

    SystemManager* mSystemManager;
    ComponentManager* mComponentManager;
    ObjectManager* mObjectManager;
    
    /* Private Constructor */
    Engine() {
        mSystemManager = new SystemManager();
        mComponentManager = new ComponentManager();
        mObjectManager = new ObjectManager();
    }

    GLFWwindow* OpenGlInit(const char * title, int windowX, int windowY);

    public:
    static Engine* getInstance() {
        if(!mEngine) {
            mEngine = new Engine();
        }
        return mEngine;
    }

    bool Init(GraphicsModule* graphicsModule);

    void terminate() {
        glfwTerminate();
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

    GLFWwindow* getWindow() {
        return mWindow;
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