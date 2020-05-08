#ifndef HESTIA_GRAPHICS_OPENGL_MODULE_HPP_
#define HESTIA_GRAPHICS_OPENGL_MODULE_HPP_

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm/glm.hpp"

#include <vector>
#include <string>
#include <map>
#include <utility>
#include <memory>

#include "GraphicsModule.hpp"
#include "Shader.hpp"
#include "Material.hpp"
#include "maths/MathsTypes.hpp"

namespace HGE {

    class OpenGlModule : public GraphicsModule {

        private:
        GLFWwindow* mWindow;
        std::string mGameTitle;
        std::map<std::pair<const char*, const char*>, std::unique_ptr<Shader>> mShaders;
        std::map<const char*, std::unique_ptr<Material>> mMaterials;

        public:
        OpenGlModule();
        ~OpenGlModule();

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