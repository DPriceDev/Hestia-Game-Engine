#include "GraphicsComponent.hpp"

#include "../framework/Engine.hpp"

#include "GraphicsSystem.hpp"

void GraphicsComponent::registerSystem() {
        Engine::getInstance()->getSystemManager()->registerSystem<GraphicsSystem>();
    }