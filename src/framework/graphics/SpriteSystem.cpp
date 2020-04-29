#include "SpriteSystem.hpp"

#include "../src/framework/Engine.hpp"

#include <iostream>

using namespace HGE;

SpriteSystem::SpriteSystem()
{
    LogDebug("Graphics System Created");
    mComponents = Engine::getInstance()->getComponentManager()->getComponentArray<SpriteComponent>();
    mGraphicsModule = Engine::getInstance()->getGraphicsModule();
}

void SpriteSystem::run() {

    SpriteComponent* spriteComponent;

    for(auto & component : *mComponents) {
        spriteComponent = dynamic_cast<SpriteComponent*>(component);

        mGraphicsModule->generateSpriteVAO(spriteComponent->mVAO, spriteComponent->mVBO, spriteComponent->mVertices);
        mGraphicsModule->drawSprite(spriteComponent->mShader, spriteComponent->mVAO);
    }
}
