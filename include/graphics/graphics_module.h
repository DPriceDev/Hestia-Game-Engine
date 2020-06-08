#ifndef HESTIA_GRAPHICS_GRAPHICS_MODULE_H
#define HESTIA_GRAPHICS_GRAPHICS_MODULE_H

#define GLM_FORCE_SILENT_WARNINGS

#include <variant>

#include "glm/glm.hpp"

#include "graphics/material.h"
#include "graphics/shader.h"
#include "input/input_types.h"
#include "maths/maths_types.h"

namespace HGE {
    using VAO = unsigned int;
    using VBO = unsigned int;
    using EBO = unsigned int;

    struct ScreenSize2f {
        int mWidth, mHeight;

        ScreenSize2f() : mWidth(0), mHeight(0) {}
        ScreenSize2f(int width, int height) : mWidth(width), mHeight(height) {}

        int &width() { return mWidth; }
        int &height() { return mHeight; }

        [[nodiscard]] float widthf() const { return static_cast<float>(mWidth); }
        [[nodiscard]] float heightf() const { return static_cast<float>(mHeight); }
    };

    class GraphicsModule {

    public:
        virtual ~GraphicsModule() = default;

        virtual bool init() = 0;
        virtual void terminate() = 0;

        virtual bool isWindowOpen() = 0;

        virtual void startFrame() = 0;
        virtual void renderFrame() = 0;

        virtual void drawSprite(Shader *pShader, Material *pMaterial, unsigned int vao, Transform2f localTransform,
                                Transform2f worldTransform, ColourRGBA tint, Pointf alpha, glm::mat4 screenProjection) = 0;

        virtual void drawInstancedSprites(VAO vao, Shader *pShader, Material *pMaterial, Transform2f &localTransform,
                                          ColourRGBA &tint, Pointf &alpha, glm::mat4 screenProjection) = 0;

        virtual void drawLine(const Shader *shader, const Vector2f &start, const Vector2f &finish, Pointf width,
                              const ColourRGB &colour, glm::mat4 &screenProjection) = 0;

        virtual void drawCircle(const Shader *shader, const Vector2f &center, const Pointf &radius, Pointf width,
                                const ColourRGB &colour, glm::mat4 &screenProjection) = 0;

        virtual Shader *getShader(const char *vertexShaderPath, const char *fragmentShaderPath) = 0;
        virtual Material *getMaterial(const char *texturePath) = 0;

        virtual void setGameTitle(const char *title) = 0;

        virtual double getGameTime() = 0;
        virtual bool getKeyValue(KeyType key) = 0;

        [[nodiscard]] virtual const ScreenSize2f &getScreenResolution() const = 0;
        virtual void setScreenResolution(const ScreenSize2f &resolution) = 0;
        virtual ScreenSize2f getScreenSize() = 0;

        virtual void generateSpriteVAO(unsigned int &vaoOut, unsigned int &vboOut, float *pVertices) = 0;
        virtual void generateInstancedSpriteVAO(unsigned int &vaoOut, unsigned int &vboOut, float *pVertices) = 0;
    };

    //    template<typename GM>
    //    concept graphics_module = std::is_base_of<GraphicsModule, GM>::value;
}// namespace HGE


#endif