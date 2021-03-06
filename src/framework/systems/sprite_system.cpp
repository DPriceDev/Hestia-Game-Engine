#include "game/systems/sprite_system.h"

#include "framework/ecs/interactors/component_array_interactor.h"
#include "framework/ecs/system_manager.h"
#include "context.h"

namespace HGE {

    System<SpriteComponent>::System(Context* context, ComponentArray<SpriteComponent> *componentArray) : mContext(context), mSpritesArray(componentArray) {
        mPositionsArray = getOrCreateComponentArray<PositionComponent>(context);
        mContext->mSystemManager->createSystem<PositionComponent>(mContext, mPositionsArray);

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