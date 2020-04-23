#ifndef INPUT_HPP
#define INPUT_HPP

#include "GLFW/glfw3.h"

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