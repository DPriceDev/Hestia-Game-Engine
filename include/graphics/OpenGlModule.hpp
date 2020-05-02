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
#include "maths/MathsTypes.hpp"

namespace HGE {

    class OpenGlModule : public GraphicsModule {

        private:
        GLFWwindow* mWindow;
        std::string mGameTitle;
        std::map<std::pair<const char*, const char*>, std::unique_ptr<Shader>> mShaders;

        public:
        OpenGlModule();
        ~OpenGlModule();

        bool init() override;
        void terminate() override;

        bool isWindowOpen() override;

        void renderFrame() override;
        void drawTriangle(Shader* pShader, unsigned int vao) override;
        void startFrame() override;

        void drawSprite(Shader* pShader, unsigned int vao, Transform2f localTransform, glm::mat4 screenProjection) override;

        Shader* getShader(const char * vertexShaderPath, const char * fragmentShaderPath) override;

        double getGameTime() override;
        void setGameTitle(const char * title) override;

        unsigned int generateVAO(unsigned int &vaoOut, unsigned int &vboOut, std::vector<Vector2f>* pVertices) override;
        void generateSpriteVAO(unsigned int &vaoOut, unsigned int &vboOut, float* pVertices) override;
    };
}


#endif