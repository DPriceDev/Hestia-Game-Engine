#ifndef HESTIA_GRAPHICS_OPENGL_MODULE_H
#define HESTIA_GRAPHICS_OPENGL_MODULE_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm/glm.hpp"

#include <vector>
#include <string>
#include <map>
#include <utility>
#include <memory>

#include "GraphicsModule.h"
#include "Shader.h"
#include "Material.h"
#include "maths/MathsTypes.h"

namespace HGE {
    class OpenGlModule : public GraphicsModule {

        GLFWwindow* mWindow;
        std::string mGameTitle;
        std::map<std::pair<const char*, const char*>, std::unique_ptr<Shader>> mShaders;
        std::map<const char*, std::unique_ptr<Material>> mMaterials;

        public:
        OpenGlModule() : 
            mShaders(std::map<std::pair<const char*, const char*>, std::unique_ptr<Shader>>()),
            mMaterials(std::map<const char*, std::unique_ptr<Material>>()), 
            mGameTitle(""), 
            mWindow(nullptr) { }
             
        ~OpenGlModule() = default;


        bool init() override;
        void terminate() override;

        bool isWindowOpen() override;

        double getGameTime() override;
        void setGameTitle(const char * title) override;

        bool getKeyValue(KeyType key) override;

        void setKeyCallback(KeyType key) override {
            
        }

        void renderFrame() override;
        void startFrame() override;

        Shader* getShader(const char * vertexShaderPath, const char * fragmentShaderPath) override;
        Material* getMaterial(const char * texturePath) override;

        void generateSpriteVAO(unsigned int &vaoOut, unsigned int &vboOut, float* pVertices) override;
        void drawSprite(Shader* pShader, Material* pMaterial, unsigned int vao, Transform2f localTransform, ColourRGBA tint, Pointf alpha, glm::mat4 screenProjection) override;
        
        void generateInstancedSpriteVAO(unsigned int &vaoOut, unsigned int &vboOut, float* pVertices) override;
        void drawInstancedSprites(VAO vao, Shader* pShader, Material* pMaterial, Transform2f &localTransform, ColourRGBA &tint, Pointf &alpha, glm::mat4 screenProjection) override;
    };
}


#endif