#ifndef HESTIA_GRAPHICS_GRAPHICSSYSTEM_HPP_
#define HESTIA_GRAPHICS_GRAPHICSSYSTEM_HPP_

#include <iostream>
#include <vector>

#include "../src/framework/ecs/System.hpp"
#include "../src/framework/ecs/Component.hpp"

#include "../src/util/Logger.hpp"

#include "GraphicsComponent.hpp"

/**
 * 
 */
class GraphicsSystem : public System {

    private:
    std::vector<Component*>* mComponents; 

    public:
    GraphicsSystem();

    ~GraphicsSystem() {
    }

    void run() override;
};

#endif