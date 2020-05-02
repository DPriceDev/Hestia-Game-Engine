#include "graphics/OpenGlModule.hpp"

#include <iostream>
#include <sstream>

#include "glm/glm/ext.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"
#include <glm/glm/gtx/transform.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#include "util/ResourceLoader.hpp"
#include "util/Logger.hpp"

using namespace HGE;

/* Function Declarations */
GLFWwindow* OpenGlInit(const char * title, int windowX, int windowY);
void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
void showFPS(GLFWwindow* pWindow, std::string &gameTitle);

ShaderProgram loadAndBuildShader(const char * vertexShaderPath, const char * fragmentShaderPath);
TextureId loadAndBuildTexture(const char * filename);
bool checkShaderLoadedCorrectly(unsigned int id);
bool checkProgramLoadedCorrectly(unsigned int id);

OpenGlModule::OpenGlModule() { 
    mShaders = std::map<std::pair<const char*, const char*>, std::unique_ptr<Shader>>();
    mMaterials = std::map<const char*, std::unique_ptr<Material>>();
}

OpenGlModule::~OpenGlModule() { }

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

/** Is Window Open */
bool OpenGlModule::isWindowOpen() {
    return !glfwWindowShouldClose(mWindow);
}

/** Start Frame */
void OpenGlModule::startFrame() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

/** Render Frame */
void OpenGlModule::renderFrame() {

    showFPS(mWindow, mGameTitle);

    glfwSwapBuffers(mWindow);
    glfwPollEvents();  
}

/* */
double OpenGlModule::getGameTime() {
    return glfwGetTime();
}

/* */
void OpenGlModule::setGameTitle(const char * title) {
    mGameTitle = title;
}

/* */
Shader* OpenGlModule::getShader(const char * vertexShaderPath, const char * fragmentShaderPath) {

    auto pair = std::make_pair(vertexShaderPath, fragmentShaderPath);
    auto it = mShaders.find(pair);

    if(it != mShaders.end()) {
        return it->second.get();
    } else {
        Logger::getInstance()->logDebug("OpenGl Module", "Shader created");
        ShaderProgram id = loadAndBuildShader(vertexShaderPath, fragmentShaderPath);
        mShaders.insert(std::make_pair(pair, std::make_unique<Shader>(id)));
        return mShaders.at(pair).get();
    }
}

/* */
Material* OpenGlModule::getMaterial(const char * texturePath) {

    auto it = mMaterials.find(texturePath);

    if(it != mMaterials.end()) {
        return it->second.get();
    } else {
        Logger::getInstance()->logDebug("OpenGl Module", "Shader created");
        TextureId id = loadAndBuildTexture(texturePath);
        mMaterials.insert(std::make_pair(texturePath, std::make_unique<Material>(id)));
        return mMaterials.at(texturePath).get();
    }
}

/* */
void OpenGlModule::generateSpriteVAO(unsigned int &vaoOut, unsigned int &vboOut, float* pVertices) {

    unsigned int indices[] = {
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };  

    unsigned int ebo;
    glGenBuffers(1, &ebo);

    glGenVertexArrays(1, &vaoOut);
    glGenBuffers(1, &vboOut);

    glBindVertexArray(vaoOut);

    glBindBuffer(GL_ARRAY_BUFFER, vboOut);
    glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), pVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    glBindVertexArray(0);
}

/* */
void OpenGlModule::drawSprite(Shader* pShader, Material* pMaterial, unsigned int vao, Transform2f localTransform, glm::mat4 screenProjection) {

    glm::mat4 translation = glm::translate(glm::mat4(1.0), glm::vec3(localTransform.mLocalPosition.x, localTransform.mLocalPosition.y, 1.0));
    glm::mat4 rotation = glm::rotate(translation, glm::radians(localTransform.mRotation), glm::vec3(0.0f, 0.0f, 1.0f));
    glm::mat4 model = glm::scale(rotation, glm::vec3(localTransform.mScale.x, localTransform.mScale.y, 1.0f));

    pMaterial->useTexture();

    pShader->useShader();
    pShader->setMat4("model", model);
    pShader->setMat4("screen", screenProjection);

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

/** Helper functions */

GLFWwindow* OpenGlInit(const char * title, int windowX, int windowY) {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(windowX, windowY, title, NULL, NULL);
    glfwMakeContextCurrent(window);

    if (window == NULL) {
        Logger::getInstance()->logError("OpenGl Module", "Failed to create GLFW window");
        return nullptr;
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        Logger::getInstance()->logError("OpenGl Module", "Failed to initialize GLAD");
        return nullptr;
    } 

    glViewport(0, 0, windowX, windowY);
    Logger::getInstance()->logDebug("OpenGl Module", "Window Initialized Successfully.");

    return window;
}

/* Frame Buffer callback */
void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

/**
 * Show Fps
 */
double lastTime;
int numberOfFrames;

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

/* */
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

TextureId loadAndBuildTexture(const char * filename) {

    unsigned int id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);

    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        Logger::getInstance()->logError("OpenGl Module", "Failed to load texture");
    }
    stbi_image_free(data);

    return id;
}

/* */
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