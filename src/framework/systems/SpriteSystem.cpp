#include "framework/systems/SpriteSystem.hpp"

#include <iostream>

#include "framework/Engine.hpp"
#include "glm/glm/ext.hpp"

namespace HGE {

    System<SpriteComponent>::System(ComponentArray<SpriteComponent>* componentArray) : mComponentsArray(componentArray) { 
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
}