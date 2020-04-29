#ifndef HESTIA_GRAPHICS_GRAPHICSMODULE_HPP_
#define HESTIA_GRAPHICS_GRAPHICSMODULE_HPP_

#include "../src/maths/MathsTypes.hpp"
#include "../src/graphics/shaders/Shader.hpp"

namespace HGE {

    class GraphicsModule {

        public:
        virtual ~GraphicsModule() { }

        virtual bool init() = 0;
        virtual void terminate() = 0;

        virtual bool isWindowOpen() = 0;

        virtual void startFrame() = 0;
        virtual void drawTriangle(Shader* pShader, unsigned int vao) = 0;
        virtual void renderFrame() = 0;

        virtual double getGameTime() = 0;
        virtual void setGameTitle(const char * title) = 0;

        virtual unsigned int generateVAO(unsigned int &vaoOut, unsigned int &vboOut, std::vector<Vector2f>* pVertices) = 0;
        virtual void generateSpriteVAO(unsigned int &vaoOut, unsigned int &vboOut, Vector2f* pVertices) = 0;
    };
}


#endif