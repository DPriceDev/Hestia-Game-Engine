//
// Created by David Price on 07/07/2020.
//

#ifndef HESTIA_GAME_ENGINE_INCLUDE_CONTEXT_H
#define HESTIA_GAME_ENGINE_INCLUDE_CONTEXT_H

namespace HGE {
    class ObjectManager;
    class ComponentManager;
    class SystemManager;
    class CameraManager;
    class InputManager;
    class GraphicsModule;

    struct Context {
        ObjectManager* mObjectManager = nullptr;
        ComponentManager* mComponentManager = nullptr;
        SystemManager *mSystemManager = nullptr;
        CameraManager *mCameraManager = nullptr;
        InputManager * mInputManager = nullptr;
        GraphicsModule *mGraphicsModule = nullptr;
    };
}

#endif //HESTIA_GAME_ENGINE_INCLUDE_CONTEXT_H
