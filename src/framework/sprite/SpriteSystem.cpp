#include "framework/sprite/SpriteSystem.hpp"

#include <iostream>

#include "framework/Engine.hpp"
#include "glm/glm/ext.hpp"

using namespace HGE;

System<SpriteComponent>::System() { 
    std::get<std::vector<std::unique_ptr<SpriteComponent>>>(mComponents) = std::vector<std::unique_ptr<SpriteComponent>>();
    mGraphicsModule = Engine::getInstance()->getGraphicsModule();

    mOrthographic = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);

    float vertices[16] = { 
        0.5, 0.5, 1.0f, 1.0f,  
        -0.5, 0.5, 0.0f, 1.0f, 
        -0.5, -0.5, 0.0f, 0.0f,
        0.5, -0.5, 1.0f, 0.0f };

    mGraphicsModule->generateSpriteVAO(mSpriteVao, mSpriteVbo, vertices);
    Logger::getInstance()->logDebug("Sprite System", "Created");
}

// System<SpriteComponent>::System() {

//     std::get<std::vector<std::unique_ptr<SpriteComponent>>>(mComponents) = std::vector<std::unique_ptr<SpriteComponent>>();
//     mGraphicsModule = Engine::getInstance()->getGraphicsModule();

//     mOrthographic = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);

//     float vertices[16] = { 
//         0.5, 0.5, 1.0f, 1.0f,  
//         -0.5, 0.5, 0.0f, 1.0f, 
//         -0.5, -0.5, 0.0f, 0.0f,
//         0.5, -0.5, 1.0f, 0.0f };

//     mGraphicsModule->generateSpriteVAO(mSpriteVao, mSpriteVbo, vertices);
//     Logger::getInstance()->logDebug("Graphics System", "Created");
// }

// void SpriteSystem::run() {

//     for(auto & component : std::get<std::vector<std::unique_ptr<SpriteComponent>>>(mComponents)) {
//         mGraphicsModule->drawSprite(component->mShader, component->mMaterial, mSpriteVao, component->mTransform, component->mTint, component->mAlpha, mOrthographic);
//     }
// }