#ifndef HESTIA_FRAMEWORK_CAMERA_SYSTEM_H
#define HESTIA_FRAMEWORK_CAMERA_SYSTEM_H

#include "framework/ecs/Component.h"
#include "framework/ecs/System.h"

#include "util/Logger.h"

namespace HGE {

    /**
     * Camera Component
     */
    struct CameraComponent : public Component {

        CameraComponent(UID ownerId) : Component(ownerId) { }
        ~CameraComponent() = default;
    };

    /**
     * Camera System
     */
    template <>
    class System<CameraComponent> : public ISystem {

        ComponentArray<CameraComponent>* mCameraArray;

        public:
        System(ComponentArray<CameraComponent>* mCameraArray) { }
        ~System() = default;

        void run() override { }
    };
}

#endif