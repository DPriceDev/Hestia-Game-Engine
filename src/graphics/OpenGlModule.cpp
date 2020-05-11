#include "graphics/OpenGlModule.h"

#include <iostream>

#include "glm/glm/ext.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#include "util/ResourceLoader.h"
#include "util/Logger.h"

namespace HGE {

    /* Function Declarations */
    GLFWwindow* OpenGlInit(const char * title, int windowX, int windowY);
    void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
    void showFPS(GLFWwindow* pWindow, std::string &gameTitle);

    ShaderProgram loadAndBuildShader(const char * vertexShaderPath, const char * fragmentShaderPath);
    TextureId loadAndBuildTexture(const char * filename);
    bool checkShaderLoadedCorrectly(unsigned int id);
    bool checkProgramLoadedCorrectly(unsigned int id);

    /* */
    bool OpenGlModule::init() {
        mWindow = OpenGlInit("2D Game Engine", 800, 600);

        if(mWindow == nullptr) {
            return false;
        }

        glfwSwapInterval(true); // vsync
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
    bool OpenGlModule::getKeyValue(KeyType key) {
        return glfwGetKey(mWindow, key) == GLFW_PRESS;
    }

    ScreenSize2f OpenGlModule::getScreenSize() {
        auto screenSize = ScreenSize2f();
        glfwGetWindowSize(mWindow, &screenSize.width(), &screenSize.height());
        return screenSize;
    }

    /* */
    Shader* OpenGlModule::getShader(const char * vertexShaderPath, const char * fragmentShaderPath) {

        auto pair = std::make_pair(vertexShaderPath, fragmentShaderPath);
        auto it = mShaders.find(pair);

        if(it != mShaders.end()) {
            return it->second.get();
        } else {
            Logger::instance()->logDebug("OpenGl Module", "Shader created");
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
            Logger::instance()->logDebug("OpenGl Module", "Shader created");
            TextureId id = loadAndBuildTexture(texturePath);
            mMaterials.insert(std::make_pair(texturePath, std::make_unique<Material>(id)));
            return mMaterials.at(texturePath).get();
        }
    }

    /* */
    void OpenGlModule::generateSpriteVAO(unsigned int &vaoOut, unsigned int &vboOut, float* pVertices) {

        unsigned int indices[] = {
            1, 0, 3,   // first triangle
            3, 1, 2    // second triangle
        };  

        unsigned int ebo;
        glGenBuffers(1, &ebo);

        glGenVertexArrays(1, &vaoOut);
        glGenBuffers(1, &vboOut);

        glBindVertexArray(vaoOut);

        glBindBuffer(GL_ARRAY_BUFFER, vboOut);
        glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(float), pVertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, 0); 

        glBindVertexArray(0);
    }

    /* To Update! */ 
    void OpenGlModule::generateInstancedSpriteVAO(unsigned int &vaoOut, unsigned int &vboOut, float* pVertices) {

    }

    /* */
    void OpenGlModule::drawSprite(Shader* pShader, Material* pMaterial, unsigned int vao, Transform2f localTransform, Transform2f worldTransform, ColourRGBA tint, Pointf alpha, glm::mat4 screenProjection) {

        glm::mat4 local = glm::mat4(1.0f);
        glm::mat4 world = glm::mat4(1.0f);

        local = glm::translate(local, glm::vec3(localTransform.mLocalPosition.x, localTransform.mLocalPosition.y, 0.0f));
        local = glm::rotate(local, glm::radians(localTransform.mRotation), glm::vec3(0.0f, 0.0f, 1.0f));
        local = glm::scale(local, glm::vec3(localTransform.mScale.x, localTransform.mScale.y, 1.0f));

        world = glm::translate(world, glm::vec3(worldTransform.mLocalPosition.x, worldTransform.mLocalPosition.y, 0.0f));
        world = glm::rotate(world, glm::radians(worldTransform.mRotation), glm::vec3(0.0f, 0.0f, 1.0f));
        world = glm::scale(world, glm::vec3(worldTransform.mScale.x, worldTransform.mScale.y, 1.0f));

        pMaterial->useTexture();
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glm::vec4 tint4f = glm::vec4(tint.x, tint.y, tint.z, tint.w);

        pShader->useShader();
        pShader->setFloat("alpha", alpha);
        pShader->setMat4("local", local);
        pShader->setMat4("world", world);

        pShader->setVec4("tint", tint4f);
        pShader->setMat4("screen", screenProjection);

        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    /* */
    void OpenGlModule::drawInstancedSprites(VAO vao, Shader* pShader, Material* pMaterial, Transform2f &localTransform, ColourRGBA &tint, Pointf &alpha, glm::mat4 screenProjection) {



        pMaterial->useTexture();
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        pShader->useShader();

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
            Logger::instance()->logError("OpenGl Module", "Failed to create GLFW window");
            return nullptr;
        }

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            Logger::instance()->logError("OpenGl Module", "Failed to initialize GLAD");
            return nullptr;
        } 

        glViewport(0, 0, windowX, windowY);
        Logger::instance()->logDebug("OpenGl Module", "Window Initialized Successfully.");

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
        glShaderSource(vertex, 1, &vShaderCode, nullptr);
        glCompileShader(vertex);
        checkShaderLoadedCorrectly(vertex);

        // fragment Shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, nullptr);
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
        stbi_set_flip_vertically_on_load(1);
        unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);

        if (data) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else {
            Logger::instance()->logError("OpenGl Module", "Failed to load texture");
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
            glGetShaderInfoLog(id, 512, nullptr, infoLog);
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
            glGetProgramInfoLog(id, 512, nullptr, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        return success;
    }
}