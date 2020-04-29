#include "SpriteSystem.hpp"

#include "../src/framework/Engine.hpp"

#include <iostream>

SpriteSystem::SpriteSystem()
{
    LogDebug("Graphics System Created");
    mComponents = Engine::getInstance()->getComponentManager()->getComponentArray<SpriteComponent>();
}

void SpriteSystem::run() {

    SpriteComponent* spriteComponent;

    for(auto & component : *mComponents) {
        spriteComponent = dynamic_cast<SpriteComponent*>(component);

        Engine::getInstance()->getGraphicsModule()->generateSpriteVAO(spriteComponent->mVAO, spriteComponent->mVBO, spriteComponent->mVertices);
        Engine::getInstance()->getGraphicsModule()->drawTriangle(spriteComponent->mShader, spriteComponent->mVAO);
    }
}