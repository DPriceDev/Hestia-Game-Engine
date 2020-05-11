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

        CameraView(Pointf width, Pointf height, Pointf x = 0.0f, Pointf y = 0.0f) : mViewportSize(Vector2f(width, height)), mViewportPosition(Vector2f(x, y)) { }    
        CameraView(Vector2f viewportSize, Vector2f viewportPosition) : mViewportSize(viewportSize), mViewportPosition(viewportPosition) { }
        CameraView() : mViewportSize(Vector2f(800.0f, 600.0f)), mViewportPosition(Vector2f()) { }
        ~CameraView() = default;
    };

    /**
     * Camera View
     */
    class CameraManager {
        GraphicsModule mGraphicsModule;
        CameraView mCurrentCameraView;

        public:
        CameraManager(GraphicsModule* graphicsModule) : mGraphicsModule(graphicsModule) {
            auto screenSize = mGraphicsModule->getScreenSize();
            mCurrentCameraView = CameraView(screenSize.widthf(), screenSize.heightf());
        }
        ~CameraManager() = default;
    };
}

#endif