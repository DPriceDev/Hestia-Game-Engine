#include "OpenGlModule.hpp"

#include <iostream>
#include <sstream>

#include "shaders/Shader.hpp"


const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";


/* Function Declarations */
GLFWwindow* OpenGlInit(const char * title, int windowX, int windowY);
void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
void showFPS(GLFWwindow* pWindow);

/**
 * 
 */
bool OpenGlModule::init() {

    mWindow = OpenGlInit("2D Game Engine", 800, 600);

    glfwSwapInterval(0);

    if(mWindow == nullptr) {
        return false;
    }

    glfwSetFramebufferSizeCallback(mWindow, FramebufferSizeCallback);

    return true;
}

void OpenGlModule::terminate() {
    glfwTerminate();
}

bool OpenGlModule::isWindowOpen() {
    return !glfwWindowShouldClose(mWindow);
}

void OpenGlModule::startFrame() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGlModule::drawTriangle(std::vector<Vector2f>* pVertices, Shader* pShader) {

    /* Set Shader to use */
    pShader->useShader();

    /* */
    float vertices[pVertices->size()*3];
    int index;
    for(auto & vertex : *pVertices) {
        vertices[index++] = vertex.x;
        vertices[index++] = vertex.y;
        vertices[index++] = 0;
    }

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 

    // draw our first triangle
    glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    glDrawArrays(GL_TRIANGLES, 0, 3);

}

void OpenGlModule::renderFrame() {

    showFPS(mWindow);

    glfwSwapBuffers(mWindow);
    glfwPollEvents();  
}

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

/** Helper Functions */
double lastTime;
int nbFrames;

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