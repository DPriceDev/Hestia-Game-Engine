#ifndef HESTIA_GRAPHICS_GRAPHICSCOMPONENT_HPP_
#define HESTIA_GRAPHICS_GRAPHICSCOMPONENT_HPP_

#include <iostream>
#include <vector>

#include "../src/framework/ecs/Component.hpp"

#include "../src/maths/MathsTypes.hpp"

#include "../src/util/Logger.hpp"

/**
 * Graphics Component
 * TODO: Switch off from a vector to array somehow?
 */
struct GraphicsComponent : public Component {
    
    public:
    GraphicsComponent() : Component("Graphics") {
        LogDebug("Graphics Component Created");
        mVertices = std::vector<Vector2f>();
    }

    ~GraphicsComponent() { }

    std::vector<Vector2f> mVertices;

    std::vector<Vector2f>* getVerticesPointer() {
        return &mVertices;
    }

    void registerSystem() override;
};

#endif