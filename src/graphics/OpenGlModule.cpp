#include "graphics/OpenGlModule.hpp"

#include <iostream>
#include <sstream>

#include "glm/glm/ext.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"
#include <glm/glm/gtx/transform.hpp>

#include "util/ResourceLoader.hpp"
#include "util/Logger.hpp"

using namespace HGE;

/* Function Declarations */
GLFWwindow* OpenGlInit(const char * title, int windowX, int windowY);
void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
void showFPS(GLFWwindow* pWindow, std::string &gameTitle);

ShaderProgram loadAndBuildShader(const char * vertexShaderPath, const char * fragmentShaderPath);
bool checkShaderLoadedCorrectly(unsigned int id);
bool checkProgramLoadedCorrectly(unsigned int id);

double lastTime;
int numberOfFrames;

OpenGlModule::OpenGlModule() { }
OpenGlModule::~OpenGlModule() { 
    // TODO: delete unique pointers
}

/**
 * Initialize Open Gl Module
 * Creates initial window.
 */
bool OpenGlModule::init() {

    mWindow = OpenGlInit("2D Game Engine", 800, 600);

    // vsync
    glfwSwapInterval(0);

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

    showFPS(mWindow, mGameTitle);

    glfwSwapBuffers(mWindow);
    glfwPollEvents();  
}

/**
 * 
 */
double OpenGlModule::getGameTime() {
    return glfwGetTime();
}

/* */
void OpenGlModule::setGameTitle(const char * title) {
    mGameTitle = title;
}

/* */
Shader* OpenGlModule::getShader(const char * vertexShaderPath, const char * fragmentShaderPath) {

    //check if shader exists, if so, return.
    auto pair = std::make_pair(vertexShaderPath, fragmentShaderPath);
    auto it = mShaders.find(pair);

    if(it != mShaders.end()) {
        Logger::getInstance()->logDebug("OpenGl Module", "Shader Retrieved");
        return it->second.get();
    } else {
         Logger::getInstance()->logDebug("OpenGl Module", "Shader created");
        ShaderProgram id = loadAndBuildShader(vertexShaderPath, fragmentShaderPath);
        mShaders.insert(std::make_pair(pair, std::make_unique<Shader>(id)));
        return mShaders.at(pair).get();
    }
}

ShaderProgram loadAndBuildShader(const char * vertexShaderPath, const char * fragmentShaderPath) {

    ShaderProgram id;
    std::string vertexCode;
    std::string fragmentCode;

    loadFileIntoString(vertexCode, vertexShaderPath);
    loadFileIntoString(fragmentCode, fragmentShaderPath);

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    unsigned int vertex, fragment;
    int success;
    char infoLog[512];
    
    // vertex Shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    checkShaderLoadedCorrectly(vertex);

    // fragment Shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    checkShaderLoadedCorrectly(fragment);
    
    // shader Program
    id = glCreateProgram();
    glAttachShader(id, vertex);
    glAttachShader(id, fragment);
    glLinkProgram(id);
    checkProgramLoadedCorrectly(id);
    
    glDeleteShader(vertex);
    glDeleteShader(fragment);

    return id;
}

/* Helper Methods */
bool checkShaderLoadedCorrectly(unsigned int id) {
    int success;
    char infoLog[512];

    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };
    return success;
}

bool checkProgramLoadedCorrectly(unsigned int id) {
    int success;
    char infoLog[512];

    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    return success;
}

/**
 * Generate VAO
 */
unsigned int OpenGlModule::generateVAO(unsigned int &vaoOut, unsigned int &vboOut, std::vector<Vector2f>* pVertices) {

    /* */
    float vertices[] = {
        0.5f,  0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };

    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };  

    unsigned int EBO;
    glGenBuffers(1, &EBO);

    glGenVertexArrays(1, &vaoOut);
    glGenBuffers(1, &vboOut);

    glBindVertexArray(vaoOut);

    // 2. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, vboOut);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // 3. then set our vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    glBindVertexArray(0);

    return vaoOut;
}

/* */
void OpenGlModule::generateSpriteVAO(unsigned int &vaoOut, unsigned int &vboOut, float* pVertices) {

    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };  

    unsigned int EBO;
    glGenBuffers(1, &EBO);

    glGenVertexArrays(1, &vaoOut);
    glGenBuffers(1, &vboOut);

    glBindVertexArray(vaoOut);

    // 2. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, vboOut);
    glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), pVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // 3. then set our vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    glBindVertexArray(0);

}

/* */
void OpenGlModule::drawSprite(Shader* pShader, unsigned int vao, Transform2f localTransform, glm::mat4 screenProjection) {

    glm::mat4 translation = glm::translate(glm::mat4(1.0), glm::vec3(localTransform.mLocalPosition.x, localTransform.mLocalPosition.y, 1.0));
    glm::mat4 rotation = glm::rotate(translation, glm::radians(localTransform.mRotation), glm::vec3(0.0f, 0.0f, 1.0f));
    glm::mat4 model = glm::scale(rotation, glm::vec3(localTransform.mScale.x, localTransform.mScale.y, 1.0f));

    // make array
    pShader->useShader();
    pShader->setMat4("model", model);
    pShader->setMat4("screen", screenProjection);

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

/**
 * Draw Triangle
 * Draws a triangle to the screen.
 * TODO: Replace with generic draw function.
 */
void HGE::OpenGlModule::drawTriangle(Shader* pShader, unsigned int vao) {

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
        Logger::getInstance()->logError("OpenGl Module", "Failed to create GLFW window");
        return nullptr;
    }

    /* If GLAD library is not loaded, log and return error. Also terminate GLFW. */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Logger::getInstance()->logError("OpenGl Module", "Failed to initialize GLAD");
        return nullptr;
    } 

    /* Set the initial window size. */
    glViewport(0, 0, windowX, windowY);
    Logger::getInstance()->logDebug("OpenGl Module", "Window Initialized Successfully.");

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
void showFPS(GLFWwindow* pWindow, std::string &gameTitle)
{
    // Measure speed
    double currentTime = glfwGetTime();
    double delta = currentTime - lastTime;
    numberOfFrames++;
    if ( delta >= 1.0 ) {

        double fps = double(numberOfFrames) / delta;

        std::stringstream ss;
        ss << gameTitle << " [" << fps << " FPS]";

        glfwSetWindowTitle(pWindow, ss.str().c_str());

        numberOfFrames = 0;
        lastTime = currentTime;
    }
}