#ifndef GRAPHICS_CONTROLLER_HPP
#define GRAPHICS_CONTROLLER_HPP

#include <vector>

#include "GLFW/glfw3.h"

#include "../framework/Object.hpp"
#include "../framework/ObjectController.hpp"

/**
 * Graphics Controller
 */
class GraphicsController
{
    private:
        
    GLFWwindow* mWindow;
    std::vector<Object*>* mViewObjects;
    ObjectController* mObjectController;

    public:
    /* Constructor */
    GraphicsController(GLFWwindow* window);

    /* Destructor */
    ~GraphicsController() {
        delete mViewObjects;
        delete mObjectController;
     }

    /* Public Methods */
    void Render();

    /* Setters and Getters */
    void SetObjectController(ObjectController* objectController) {
        mObjectController = objectController;
    }

    void ClearObjectController() {
        delete mViewObjects;
        mViewObjects = new std::vector<Object*>();
        delete mObjectController;
    }
};

#endif