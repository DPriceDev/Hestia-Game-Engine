#include "framework/graphics/GraphicsSystem.hpp"

#include "framework/Engine.hpp"

#include <iostream>

namespace HGE {

    GraphicsSystem::GraphicsSystem()
    {
        LogDebug("Graphics System", "Created");
        mComponents = Engine::getInstance()->getComponentManager()->getComponentArray<GraphicsComponent>();
    }

    void GraphicsSystem::run() {

        GraphicsComponent* graphicsComponent;

        for(auto & component : *mComponents) {
            graphicsComponent = dynamic_cast<GraphicsComponent*>(component);

            Engine::getInstance()->getGraphicsModule()->generateVAO(graphicsComponent->mVAO, graphicsComponent->mVBO, graphicsComponent->getVerticesPointer());
            Engine::getInstance()->getGraphicsModule()->drawTriangle(graphicsComponent->mShader, graphicsComponent->mVAO);
        }
    }
}