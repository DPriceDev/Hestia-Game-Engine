#include "GraphicsComponent.hpp"

#include "../src/framework/Engine.hpp"

#include "GraphicsSystem.hpp"

namespace HGE {

    void GraphicsComponent::registerSystem() {
        Engine::getInstance()->getSystemManager()->registerSystem<GraphicsSystem>();
    }
}