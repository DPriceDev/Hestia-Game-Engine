#include "OpenGlModule.hpp"

#include <iostream>
#include <sstream>

#include "shaders/Shader.hpp"

/* Function Declarations */
GLFWwindow* OpenGlInit(const char * title, int windowX, int windowY);
void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
void showFPS(GLFWwindow* pWindow);

/* Local Variables */
//Shader* shader = new Shader("./assets/shaders/vertexShader.vs", "./assets/shaders/fragmentShader.fs");
double lastTime;
int nbFrames;

/**
 * Initialize Open Gl Module
 * Creates initial window.
 */
bool OpenGlModule::init() {

    mWindow = OpenGlInit("2D Game Engine", 800, 600);

    // vsync
    //glfwSwapInterval(0);

    if(mWindow == nullptr) {
        return false;
    }

    glfwSetFramebufferSizeCallback(mWindow, FramebufferSizeCallback);

    return true;
}

/**
 * Terminate Open Gl Module
 */
void OpenGlModule::terminate() {
    glfwTerminate();
}

/**
 * Is Window Open
 * Checks if the glfw window is open.
 */
bool OpenGlModule::isWindowOpen() {
    return !glfwWindowShouldClose(mWindow);
}

/**
 * Start Frame
 * Called when beginning a frame, i.e. before drawing sprites.
 */
void OpenGlModule::startFrame() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

/**
 * Render Frame
 * Called after drawing has completed.
 * swaps the frame into the active buffer.
 */
void OpenGlModule::renderFrame() {

    showFPS(mWindow);

    glfwSwapBuffers(mWindow);
    glfwPollEvents();  
}

/**
 * 
 */
double OpenGlModule::getGameTime() {
    return glfwGetTime();
}

/**
 * Generate VAO
 */
unsigned int OpenGlModule::generateVAO(unsigned int &vaoOut, unsigned int &vboOut, std::vector<Vector2f>* pVertices) {

    /* */
    float vertices[pVertices->size()*3];
    int index;
    for(auto & vertex : *pVertices) {
        vertices[index++] = vertex.x;
        vertices[index++] = vertex.y;
        vertices[index++] = 0;
    }

    glGenVertexArrays(1, &vaoOut);
    glGenBuffers(1, &vboOut);

    glBindVertexArray(vaoOut);

    // 2. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, vboOut);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // 3. then set our vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    glBindVertexArray(0);

    return vaoOut;
}

void OpenGlModule::generateSpriteVAO(unsigned int &vaoOut, unsigned int &vboOut, Vector2f* pVertices) {

    float vertices[12];
    int index;
    for(int i = 0; i < 3; i++) {
        Vector2f vertex = pVertices[i];
        vertices[index++] = vertex.x;
        vertices[index++] = vertex.y;
        vertices[index++] = 0;
    }

    glGenVertexArrays(1, &vaoOut);
    glGenBuffers(1, &vboOut);

    glBindVertexArray(vaoOut);

    // 2. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, vboOut);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // 3. then set our vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    glBindVertexArray(0);
}

/**
 * Draw Triangle
 * Draws a triangle to the screen.
 * TODO: Replace with generic draw function.
 */
void OpenGlModule::drawTriangle(Shader* pShader, unsigned int vao) {

    /* Set Shader to use */
    pShader->useShader();
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

// ---------------------------------------------------------------- //

/**
 * OpenGl Initialization
 * 
 * returns true if initialized correctly.
 */
GLFWwindow* OpenGlInit(const char * title, int windowX, int windowY) {

    /* Initialize GLFW and set the window params. */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    // const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    // glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    // glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    // glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    // glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

    // GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, title, monitor, NULL);

    GLFWwindow* window = glfwCreateWindow(windowX, windowY, title, NULL, NULL);

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

void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

/**
 * Show Fps
 * Displays Fps in the title bar.
 */
void showFPS(GLFWwindow* pWindow)
{
    // Measure speed
     double currentTime = glfwGetTime();
     double delta = currentTime - lastTime;
     nbFrames++;
     if ( delta >= 1.0 ){ // If last cout was more than 1 sec ago

         double fps = double(nbFrames) / delta;

         std::stringstream ss;
         ss << "title" << " " << "v1" << " [" << fps << " FPS]";

         glfwSetWindowTitle(pWindow, ss.str().c_str());

         nbFrames = 0;
         lastTime = currentTime;
     }
}