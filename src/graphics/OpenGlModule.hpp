#ifndef HESTIA_GRAPHICS_OPENGL_MODULE_HPP_
#define HESTIA_GRAPHICS_OPENGL_MODULE_HPP_

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <vector>
#include <string>

#include "GraphicsModule.hpp"

namespace HGE {

    class OpenGlModule : public HGE::GraphicsModule {

        private:
        GLFWwindow* mWindow;
        std::string mGameTitle;

        public:
        OpenGlModule() {

        }

        ~OpenGlModule() {

        }

        bool init() override;
        void terminate() override;

        bool isWindowOpen() override;

        void renderFrame() override;
        void drawTriangle(Shader* pShader, unsigned int vao) override;
        void startFrame() override;

        double getGameTime() override;
        void setGameTitle(const char * title) override;

        unsigned int generateVAO(unsigned int &vaoOut, unsigned int &vboOut, std::vector<Vector2f>* pVertices) override;
        void generateSpriteVAO(unsigned int &vaoOut, unsigned int &vboOut, Vector2f* pVertices) override;
    };
}


#endif