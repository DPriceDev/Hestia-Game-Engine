#ifndef HESTIA_FRAMEWORK_CAMERA_SYSTEM_H
#define HESTIA_FRAMEWORK_CAMERA_SYSTEM_H

#include "camera/camera_manager.h"
#include "context.h"
#include "framework/ecs/component.h"
#include "framework/ecs/system.h"

#include "util/logger.h"

namespace HGE {

    /**
     * Camera IComponent
     */
    struct CameraComponent : public IComponent {
        CameraView mCameraView;
        bool mIsActiveCamera, mIsRequestingActive;

        CameraComponent(UID ownerId, CameraView cameraView, bool requestCamera = false)
            : IComponent(ownerId),
              mCameraView(cameraView),
              mIsActiveCamera(false),
              mIsRequestingActive(requestCamera) {}
        ~CameraComponent() override = default;
    };

    /**
     * Camera System
     */
    template<>
    class System<CameraComponent> : public ISystem {
        Context* mContext;
        ComponentArray<CameraComponent> *mCameraArray;

    public:
        explicit System(Context* context, ComponentArray<CameraComponent> *cameraArray) : mContext(context), mCameraArray(cameraArray) {}
        ~System() override = default;

        void run(const double &deltaTime) override {

            auto requestIt = find_if(mCameraArray->getComponents().begin(), mCameraArray->getComponents().end(),
                                     [](auto const &pComponent) { return pComponent->mIsRequestingActive == true; });

            if (requestIt != mCameraArray->getComponents().end()) {

                for (auto &component : mCameraArray->getComponents()) {
                    component->mIsActiveCamera = false;
                }

                requestIt->get()->mIsActiveCamera = true;
                requestIt->get()->mIsRequestingActive = false;
                mContext->mCameraManager->setCameraView(requestIt->get()->mCameraView);
            } else {
                auto activeIt = find_if(mCameraArray->getComponents().begin(), mCameraArray->getComponents().end(),
                                        [](auto const &pComponent) { return pComponent->mIsActiveCamera == true; });
                if (activeIt != mCameraArray->getComponents().end()) {
                    mContext->mCameraManager->setCameraView(activeIt->get()->mCameraView);
                }
            }
        }
    };
}// namespace HGE

#endif