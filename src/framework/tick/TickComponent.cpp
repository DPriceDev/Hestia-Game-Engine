#include "TickComponent.hpp"

#include "../src/framework/Engine.hpp"

#include "TickSystem.hpp"

void TickComponent::registerSystem() {
        Engine::getInstance()->getSystemManager()->registerSystem<TickSystem>();
}