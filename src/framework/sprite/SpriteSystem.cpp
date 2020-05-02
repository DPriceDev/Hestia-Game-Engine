#include "framework/sprite/SpriteSystem.hpp"

#include <iostream>

#include "framework/Engine.hpp"
#include "glm/glm/ext.hpp"

using namespace HGE;

SpriteSystem::SpriteSystem()
{
    Logger::getInstance()->logDebug("Graphics System", "Created");
    mComponents = Engine::getInstance()->getComponentManager()->getComponentArray<SpriteComponent>();
    mGraphicsModule = Engine::getInstance()->getGraphicsModule();

    mOrthographic = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);

    float vertices[16] = { 
        0.5, 0.5, 1.0f, 1.0f,  
        -0.5, 0.5, 0.0f, 1.0f, 
        -0.5, -0.5, 0.0f, 0.0f,
        0.5, -0.5, 1.0f, 0.0f };

    mGraphicsModule->generateSpriteVAO(mSpriteVao, mSpriteVbo, vertices);
}

void SpriteSystem::run() {
    SpriteComponent* spriteComponent;

    for(auto & component : *mComponents) {
        spriteComponent = dynamic_cast<SpriteComponent*>(component);

        mGraphicsModule->drawSprite(spriteComponent->mShader, spriteComponent->mMaterial, mSpriteVao, spriteComponent->mTransform, spriteComponent->mTint, spriteComponent->mAlpha, mOrthographic);
    }
}