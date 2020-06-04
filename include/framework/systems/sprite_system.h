#ifndef HESTIA_FRAMEWORK_SPRITE_SYSTEM_H
#define HESTIA_FRAMEWORK_SPRITE_SYSTEM_H

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <vector>

#include "camera/camera_manager.h"
#include "framework/ecs/component.h"
#include "framework/ecs/component_manager.h"
#include "framework/ecs/system.h"
#include "framework/systems/position_system.h"

#include "graphics/graphics_module.h"

#include "util/logger.h"

namespace HGE {

    /**
     * Sprite IComponent
     */
    struct SpriteComponent : public IComponent {

        Transform2f mTransform;
        Shader *mShader{};
        Material *mMaterial{};
        ColourRGBA mTint;
        Pointf mAlpha;

        explicit SpriteComponent(UID ownerId) : IComponent(ownerId), mTransform(Transform2f()), mTint(ColourRGBA()), mAlpha(1.0f) {}
        ~SpriteComponent() override = default;
    };

    /**
     * Sprite System
     */
    template<>
    class System<SpriteComponent> : public ISystem {

        ComponentManager *mComponentManager;
        ComponentArray<SpriteComponent> *mSpritesArray;
        ComponentArray<PositionComponent> *mPositionsArray;
        GraphicsModule *mGraphicsModule;
        CameraManager *mCameraManager;
        unsigned int mSpriteVao, mSpriteVbo;
        glm::mat4 mOrthographic;

    public:
        explicit System(ComponentArray<SpriteComponent> *componentArray);

        ~System() override = default;

        void run(const double &deltaTime) override {
            mOrthographic = glm::ortho(mCameraManager->getViewportLeft(),
                                       mCameraManager->getViewportRight(),
                                       mCameraManager->getViewportBottom(),
                                       mCameraManager->getViewportTop());

            for (auto const &component : mSpritesArray->getComponents()) {
                auto worldComponent = mPositionsArray->getComponentWithOwner(component->getOwnerUID());

                if (worldComponent != nullptr) {
                    mGraphicsModule->drawSprite(component->mShader, component->mMaterial, mSpriteVao, component->mTransform, worldComponent->mTransform, component->mTint, component->mAlpha, mOrthographic);
                } else {
                    Logger::instance()->logDebug("Sprite System", " No Position component available for object!");
                }
            }
        }
    };
}// namespace HGE

#endif