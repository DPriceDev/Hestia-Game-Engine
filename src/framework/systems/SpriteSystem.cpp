#include "framework/systems/SpriteSystem.h"

#include <glm/glm/ext.hpp>

#include "framework/Engine.h"

namespace HGE {

    System<SpriteComponent>::System(ComponentArray<SpriteComponent>* componentArray) : mSpritesArray(componentArray) { 
        mGraphicsModule = Engine::graphicsModule();
        mCameraManager = Engine::cameraManager();
        mComponentManager = Engine::componentManager();
        mPositionsArray = mComponentManager->getComponentArray<WorldPositionComponent>();

        mOrthographic = glm::ortho(mCameraManager->getViewportLeft(),
                                   mCameraManager->getViewportRight(),
                                   mCameraManager->getViewportBottom(),
                                   mCameraManager->getViewportTop());

        float vertices[16] = { 
            1.0f, 1.0f, 1.0f, 1.0f,
            0.0f, 1.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 1.0f, 0.0f };

        mGraphicsModule->generateSpriteVAO(mSpriteVao, mSpriteVbo, vertices);
        Logger::instance()->logDebug("Sprite System", "Created");
    }
}