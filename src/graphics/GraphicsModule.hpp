#ifndef HESTIA_GRAPHICS_GRAPHICSMODULE_HPP_
#define HESTIA_GRAPHICS_GRAPHICSMODULE_HPP_

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
    virtual void drawTriangle() = 0;
    virtual void renderFrame() = 0;
};


#endif