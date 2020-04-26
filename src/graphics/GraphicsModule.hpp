#ifndef HESTIA_GRAPHICS_GRAPHICSMODULE_HPP_
#define HESTIA_GRAPHICS_GRAPHICSMODULE_HPP_

/**
 * 
 */
class GraphicsModule {

    public:
    virtual ~GraphicsModule() { }

    virtual bool init() = 0;
};


#endif