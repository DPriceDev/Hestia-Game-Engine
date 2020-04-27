#include "TickSystem.hpp"

#include "../src/framework/Engine.hpp"

#include <iostream>

TickSystem::TickSystem()
{
    mComponents = Engine::getInstance()->getComponentManager()->getComponentArray<TickComponent>();
}

void TickSystem::run() {

    // get delta time
    float deltaTime = 0.5;

    for(auto & component : *mComponents) {
        TickComponent* tickComponent = dynamic_cast<TickComponent*>(component);

    }
}