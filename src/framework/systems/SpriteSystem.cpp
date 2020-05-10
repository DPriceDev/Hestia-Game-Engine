#include "framework/systems/SpriteSystem.h"

#include <iostream>
#include <glm/glm/ext.hpp>

#include "framework/Engine.h"

namespace HGE {

    System<SpriteComponent>::System(ComponentArray<SpriteComponent>* componentArray) : mSpritesArray(componentArray) { 
        mGraphicsModule = Engine::instance()->graphicsModule();
        mComponentManager = Engine::instance()->componentManager();
        mPositionsArray = mComponentManager->getComponentArray<WorldPositionComponent>();

        auto screenSize = mGraphicsModule->getScreenSize();
        mOrthographic = glm::ortho(0.0f, screenSize.widthf(), 0.0f, screenSize.heightf());

        float vertices[16] = { 
            0.5, 0.5, 1.0f, 1.0f,  
            -0.5, 0.5, 0.0f, 1.0f, 
            -0.5, -0.5, 0.0f, 0.0f,
            0.5, -0.5, 1.0f, 0.0f };

        mGraphicsModule->generateSpriteVAO(mSpriteVao, mSpriteVbo, vertices);
        Logger::instance()->logDebug("Sprite System", "Created");
    }
}