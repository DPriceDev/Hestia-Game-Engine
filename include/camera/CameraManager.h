#ifndef HESTIA_CAMERA_CAMERA_MANAGER_H
#define HESTIA_CAMERA_CAMERA_MANAGER_H

#include "graphics/GraphicsModule.h"
#include "maths/MathsTypes.h"

namespace HGE {

    /**
     * Camera View
     */
    struct CameraView {
        Vector2f mViewportSize;
        Vector2f mViewportPosition;
        Pointf mRotation;

        CameraView(Pointf width, Pointf height, Pointf x = 0.0f, Pointf y = 0.0f, Pointf rotation = 0.0f)
                      : mViewportSize(Vector2f(width, height)),
                        mViewportPosition(Vector2f(x, y)),
                        mRotation(rotation) { }

        explicit CameraView(Vector2f viewportSize, Vector2f viewportPosition = Vector2f()) : mViewportSize(viewportSize),
                        mViewportPosition(viewportPosition),
                        mRotation(0.0f) { }

        CameraView() : mViewportSize(Vector2f(800.0f, 600.0f)),
                        mViewportPosition(Vector2f()),
                        mRotation(0) { }

        ~CameraView() = default;
    };

    /**
     * Camera View
     */
    class CameraManager {
        CameraView mCurrentCameraView;
        GraphicsModule* mGraphicsModule;

    public:
        explicit CameraManager(GraphicsModule* graphicsModule) : mGraphicsModule(graphicsModule) {
            mCurrentCameraView = CameraView(
                    mGraphicsModule->getScreenResolution().widthf(),
                    mGraphicsModule->getScreenResolution().heightf());
        }
        ~CameraManager() = default;

        void setCameraView(const CameraView& cameraView) {
            mCurrentCameraView = cameraView;
        }

        [[nodiscard]] const Vector2f& getViewportSize() const {
            return mCurrentCameraView.mViewportSize;
        }
        [[nodiscard]] const Vector2f& getViewportPosition() const {
            return mCurrentCameraView.mViewportPosition;
        }
        [[nodiscard]] const Pointf& getViewportRotation() const {
            return mCurrentCameraView.mRotation;
        }
        [[nodiscard]] Pointf getViewportTop() const {
            return mCurrentCameraView.mViewportSize.y + mCurrentCameraView.mViewportPosition.y;
        }
        [[nodiscard]] const Pointf& getViewportBottom() const {
            return mCurrentCameraView.mViewportPosition.y;
        }
        [[nodiscard]] const Pointf& getViewportLeft() const {
            return mCurrentCameraView.mViewportPosition.x;
        }
        [[nodiscard]] Pointf getViewportRight() const {
            return mCurrentCameraView.mViewportSize.x + mCurrentCameraView.mViewportPosition.x;
        }
    };
}

#endif