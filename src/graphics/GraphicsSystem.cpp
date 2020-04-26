#include "GraphicsSystem.hpp"

#include "../framework/Engine.hpp"

GraphicsSystem::GraphicsSystem()
{
    LogDebug("Graphics System Created");
    mComponents = Engine::getInstance()->getComponentManager()->getComponentArray<GraphicsComponent>();
}