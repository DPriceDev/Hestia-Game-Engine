#include "GraphicsSystem.hpp"

#include "../src/framework/Engine.hpp"

#include <iostream>

GraphicsSystem::GraphicsSystem()
{
    LogDebug("Graphics System Created");
    mComponents = Engine::getInstance()->getComponentManager()->getComponentArray<GraphicsComponent>();
}

void GraphicsSystem::run() {

    Engine::getInstance()->getGraphicsModule()->startFrame();

    for(auto & component : *mComponents) {
        GraphicsComponent* graphicsComponent = dynamic_cast<GraphicsComponent*>(component);

        // DO THING HERE!
        Engine::getInstance()->getGraphicsModule()->drawTriangle(graphicsComponent->getVerticesPointer());
    }

    Engine::getInstance()->getGraphicsModule()->renderFrame();
}