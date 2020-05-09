#include "framework/systems/SpriteSystem.h"

#include <iostream>
#include <glm/glm/ext.hpp>

#include "framework/Engine.h"

namespace HGE {

    System<SpriteComponent>::System(ComponentArray<SpriteComponent>* componentArray) : mSpritesArray(componentArray) { 
        mGraphicsModule = Engine::getInstance()->getGraphicsModule();
        mComponentManager = Engine::getInstance()->getComponentManager();
        mPositionsArray = mComponentManager->getComponentArray<WorldPositionComponent>();

        mOrthographic = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);

        float vertices[16] = { 
            0.5, 0.5, 1.0f, 1.0f,  
            -0.5, 0.5, 0.0f, 1.0f, 
            -0.5, -0.5, 0.0f, 0.0f,
            0.5, -0.5, 1.0f, 0.0f };

        mGraphicsModule->generateSpriteVAO(mSpriteVao, mSpriteVbo, vertices);
        Logger::getInstance()->logDebug("Sprite System", "Created");
    }
}