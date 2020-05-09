#ifndef HESTIA_GRAPHICS_GRAPHICS_MODULE_H
#define HESTIA_GRAPHICS_GRAPHICS_MODULE_H

#include "glm/glm/glm.hpp"

#include "input/InputTypes.h"
#include "maths/MathsTypes.h"
#include "graphics/Shader.h"
#include "graphics/Material.h"

namespace HGE {
    using VAO = unsigned int;
    using VBO = unsigned int;
    using EBO = unsigned int;

    class GraphicsModule {

        public:
        virtual ~GraphicsModule() = default;

        virtual bool init() = 0;
        virtual void terminate() = 0;

        virtual bool isWindowOpen() = 0;

        virtual void startFrame() = 0;
        virtual void renderFrame() = 0;

        virtual void drawSprite(Shader* pShader, Material* pMaterial, unsigned int vao, Transform2f localTransform, Transform2f worldTransform, ColourRGBA tint, Pointf alpha, glm::mat4 screenProjection) = 0;
        virtual void drawInstancedSprites(VAO vao, Shader* pShader, Material* pMaterial, Transform2f &localTransform, ColourRGBA &tint, Pointf &alpha, glm::mat4 screenProjection) = 0;

        virtual Shader* getShader(const char * vertexShaderPath, const char * fragmentShaderPath) = 0;
        virtual Material* getMaterial(const char * texturePath) = 0;

        virtual double getGameTime() = 0;
        virtual void setGameTitle(const char * title) = 0;

        virtual void setKeyCallback(KeyType key) = 0;
        virtual bool getKeyValue(KeyType key) = 0;

        virtual void generateSpriteVAO(unsigned int &vaoOut, unsigned int &vboOut, float* pVertices) = 0;
        virtual void generateInstancedSpriteVAO(unsigned int &vaoOut, unsigned int &vboOut, float* pVertices) = 0;
    };
}


#endif