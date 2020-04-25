#ifndef INPUT_CONTROLLER_HPP
#define INPUT_CONTROLLER_HPP

#include "GLFW/glfw3.h"

/**
 * Input Controller
 */
class InputController
{
    public:
    /* Constructor */
    InputController() { }

    /* Destructor */
    ~InputController() { }

    /* Public Methods */
    void processInput(GLFWwindow *window);

    private:
};

#endif