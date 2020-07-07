#include "framework/systems/sprite_system.h"

#include "framework/ecs/component_manager.h"

namespace HGE {

    System<SpriteComponent>::System(Context* context, ComponentArray<SpriteComponent> *componentArray) : mContext(context), mSpritesArray(componentArray) {
        mPositionsArray = mContext->mComponentManager->getComponentArray<PositionComponent>();

        mOrthographic = glm::ortho(mContext->mCameraManager->getViewportLeft(),
                                   mContext->mCameraManager->getViewportRight(),
                                   mContext->mCameraManager->getViewportBottom(),
                                   mContext->mCameraManager->getViewportTop());

        float vertices[16] = {
                1.0f, 1.0f, 1.0f, 1.0f,
                0.0f, 1.0f, 0.0f, 1.0f,
                0.0f, 0.0f, 0.0f, 0.0f,
                1.0f, 0.0f, 1.0f, 0.0f};

        mContext->mGraphicsModule->generateSpriteVAO(mSpriteVao, mSpriteVbo, vertices);
        Logger::instance()->logDebug("Sprite System", "Created");
    }
}// namespace HGE