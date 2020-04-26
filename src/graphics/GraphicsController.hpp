#ifndef GRAPHICS_CONTROLLER_HPP
#define GRAPHICS_CONTROLLER_HPP

#include <vector>

#include "GLFW/glfw3.h"

#include "../src/framework/ecs/Object.hpp"

#define GL_SILENCE_DEPRECATION

/**
 * Graphics Controller
 */
class GraphicsController
{
    public:
    /* Constructor */
    GraphicsController();

    /* Destructor */
    ~GraphicsController() { }
};

#endif