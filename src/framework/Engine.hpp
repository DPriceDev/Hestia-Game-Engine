#ifndef HESTIA_FRAMEWORK_ENGINE_H_
#define HESTIA_FRAMEWORK_ENGINE_H_

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "ecs/SystemManager.hpp"
#include "ecs/ComponentManager.hpp"
#include "ecs/ObjectManager.hpp"

#include "../src/framework/graphics/GraphicsSystem.hpp"

/**
 * Engine Class
 * Provides a static singletion
 */
class Engine {
    
    private:
    /* Private Variables */
    static Engine* mEngine;
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

    bool Init();

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

    ~Engine() { 
        delete mEngine;
        delete mSystemManager;
        delete mComponentManager;
        delete mObjectManager;
    }
};

#endif