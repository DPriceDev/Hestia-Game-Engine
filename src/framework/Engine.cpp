#include "Engine.hpp"

/* */
bool Engine::Init() {

    mWindow = OpenGlInit("2D Game Engine", 800, 600);

    if(mWindow == nullptr) {
        return false;
    }

    return true;
}



/**
 * OpenGl Initialization
 * 
 * returns true if initialized correctly.
 */
GLFWwindow* Engine::OpenGlInit(const char * title, int windowX, int windowY) {

    /* Initialize GLFW and set the window params. */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

   GLFWwindow* window = glfwCreateWindow(800, 600, "title", NULL, NULL);

    /* Initialize the window and apply it as the current GLFW context. add window resize callback. */
    glfwMakeContextCurrent(window);

    /* If the window is not created, log and return error. Also terminate GLFW. */
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        return nullptr;
    }

    /* If GLAD library is not loaded, log and return error. Also terminate GLFW. */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return nullptr;
    } 

    /* Set the initial window size. */
    glViewport(0, 0, windowX, windowY);
    std::cout << "Window Initialized" << std::endl;

    return window;
}