#ifndef HESTIA_GRAPHICS_GRAPHICSSYSTEM_HPP_
#define HESTIA_GRAPHICS_GRAPHICSSYSTEM_HPP_

#include <iostream>
#include <vector>

#include "../framework/systems/system.hpp"
#include "../framework/components/Component.hpp"

#include "../util/Logger.hpp"

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