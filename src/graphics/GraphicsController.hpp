#ifndef GRAPHICS_CONTROLLER_HPP
#define GRAPHICS_CONTROLLER_HPP

#include <vector>

#include "GLFW/glfw3.h"

#include "../framework/objects/Object.hpp"
#include "Viewable.hpp"

/**
 * Graphics Controller
 */
class GraphicsController
{
    private:
    GLFWwindow* mWindow;
    std::vector<Viewable*> mViewObjects;

    unsigned int VBO;

    public:
    /* Constructor */
    GraphicsController(GLFWwindow* window);

    /* Destructor */
    ~GraphicsController() { }

    /* Public Methods */
    void Render();

    void AddViewable(Viewable* viewable) {
        auto it = std::find(mViewObjects.begin(), mViewObjects.end(), viewable);
        if(it == mViewObjects.end()) {
            mViewObjects.push_back(viewable);
        }
    }

    void RemoveViewable(Viewable* viewable) {
        auto it = std::find(mViewObjects.begin(), mViewObjects.end(), viewable);
        if(it != mViewObjects.end()) {
            mViewObjects.erase(it);
        }
    }

    void ClearViewables() {
        mViewObjects.clear();
    }
};

#endif