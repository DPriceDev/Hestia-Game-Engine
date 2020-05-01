#include "framework/graphics/GraphicsComponent.hpp"

#include "framework/Engine.hpp"

#include "framework/graphics/GraphicsSystem.hpp"

namespace HGE {

    void GraphicsComponent::registerSystem() {
        Engine::getInstance()->getSystemManager()->registerSystem<GraphicsSystem>();
    }
}