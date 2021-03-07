#ifndef HESTIA_GRAPHICS_OPENGL_MODULE_H
#define HESTIA_GRAPHICS_OPENGL_MODULE_H

#define GLM_FORCE_CXX17
#define GLM_FORCE_SILENT_WARNINGS

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "graphics_module.h"
#include "material.h"
#include "maths/maths_types.h"
#include "shader.h"

namespace HGE {
    class OpenglModule : public GraphicsModule {

        GLFWwindow *mWindow{nullptr};
        std::string mGameTitle;
        ScreenSize2f mResolution;
        std::map<std::pair<const char *, const char *>, std::unique_ptr<Shader>> mShaders;
        std::map<const char *, std::unique_ptr<Material>> mMaterials;

    public:
        OpenglModule() : mShaders(std::map<std::pair<const char *, const char *>, std::unique_ptr<Shader>>()),
                         mMaterials(std::map<const char *, std::unique_ptr<Material>>()),
                         mResolution(ScreenSize2f(800, 600)) {}

        ~OpenglModule() override = default;

        bool init() override;
        void terminate() override;

        bool isWindowOpen() override;

        double getGameTime() override;
        void setGameTitle(const char *title) override;

        bool getKeyValue(KeyType key) override;
        ScreenSize2f getScreenSize() override;

        [[nodiscard]] const ScreenSize2f &getScreenResolution() const override;
        void setScreenResolution(const ScreenSize2f &resolution) override;

        void renderFrame() override;
        void startFrame() override;

        Shader *getShader(const char *vertexShaderPath, const char *fragmentShaderPath) override;
        Material *getMaterial(const char *texturePath) override;

        void generateSpriteVAO(unsigned int &vaoOut, unsigned int &vboOut, float *pVertices) override;
        void drawSprite(Shader *pShader, Material *pMaterial, unsigned int vao, Transform2f localTransform,
                        Transform2f worldTransform, ColourRGBA tint, Pointf alpha, glm::mat4 screenProjection) override;

        void generateInstancedSpriteVAO(unsigned int &vaoOut, unsigned int &vboOut, float *pVertices) override;
        void drawInstancedSprites(VAO vao, Shader *pShader, Material *pMaterial, Transform2f &localTransform,
                                  ColourRGBA &tint, Pointf &alpha, glm::mat4 screenProjection) override;

        void drawLine(const Shader *shader, const Vector2f &start, const Vector2f &finish, Pointf width,
                      const ColourRGB &colour, glm::mat4 &screenProjection) override;

        void drawCircle(const Shader *shader, const Vector2f &center, const Pointf &radius, Pointf width,
                        const ColourRGB &colour, glm::mat4 &screenProjection) override;
    };
}// namespace HGE


#endif