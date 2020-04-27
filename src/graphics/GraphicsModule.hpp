#ifndef HESTIA_GRAPHICS_GRAPHICSMODULE_HPP_
#define HESTIA_GRAPHICS_GRAPHICSMODULE_HPP_

#include "../src/maths/MathsTypes.hpp"

/**
 * 
 */
class GraphicsModule {

    public:
    virtual ~GraphicsModule() { }

    virtual bool init() = 0;
    virtual void terminate() = 0;

    virtual bool isWindowOpen() = 0;

    virtual void startFrame() = 0;
    virtual void drawTriangle(std::vector<Vector2f>* pVertices) = 0;
    virtual void renderFrame() = 0;
};


#endif