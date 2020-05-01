#include "SpriteSystem.hpp"

#include "../src/framework/Engine.hpp"
#include "glm/ext.hpp"

#include <iostream>

using namespace HGE;

SpriteSystem::SpriteSystem()
{
    LogDebug("Graphics System Created");
    mComponents = Engine::getInstance()->getComponentManager()->getComponentArray<SpriteComponent>();
    mGraphicsModule = Engine::getInstance()->getGraphicsModule();

    mOrthographic = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);

    float vertices[] = { -0.5, 0.5, 0.5, 0.5, -0.5, -0.5, 0.5, -0.5 };
    mGraphicsModule->generateSpriteVAO(mSpriteVao, mSpriteVbo, vertices);
}

void SpriteSystem::run() {
    SpriteComponent* spriteComponent;

    for(auto & component : *mComponents) {
        spriteComponent = dynamic_cast<SpriteComponent*>(component);

        mGraphicsModule->drawSprite(spriteComponent->mShader, mSpriteVao, spriteComponent->mTransform, mOrthographic);
    }
}