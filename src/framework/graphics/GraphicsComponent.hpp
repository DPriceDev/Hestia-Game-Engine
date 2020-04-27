#ifndef HESTIA_GRAPHICS_GRAPHICSCOMPONENT_HPP_
#define HESTIA_GRAPHICS_GRAPHICSCOMPONENT_HPP_

#include <iostream>
#include <vector>

#include "../src/framework/ecs/Component.hpp"

#include "../src/util/Logger.hpp"

/**
 * 
 */
struct GraphicsComponent : public Component {

    public:
    GraphicsComponent() : Component("Graphics") {
        LogDebug("Graphics Component Created");
    }

    float mVertices[];

    ~GraphicsComponent() { }

    void registerSystem() override;
};

#endif