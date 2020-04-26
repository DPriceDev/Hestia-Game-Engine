#ifndef HESTIA_GRAPHICS_GRAPHICSCOMPONENT_HPP_
#define HESTIA_GRAPHICS_GRAPHICSCOMPONENT_HPP_

#include <iostream>
#include <vector>

#include "../framework/components/Component.hpp"

#include "../util/Logger.hpp"

/**
 * 
 */
struct GraphicsComponent : public Component {

    public:
    GraphicsComponent() : Component("Graphics") {
        LogDebug("Graphics Component Created");
    }

    ~GraphicsComponent() {
        
    }

    void registerSystem() override;
};

#endif