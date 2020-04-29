#include "SpriteComponent.hpp"

#include "../src/framework/Engine.hpp"

#include "SpriteSystem.hpp"

void SpriteComponent::registerSystem() {
        Engine::getInstance()->getSystemManager()->registerSystem<SpriteSystem>();
    }