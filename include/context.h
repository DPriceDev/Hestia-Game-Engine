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

    /**
     * Context Object
     * Provides context to the different managers
     * todo: split ECS context out?
     * todo: split out graphics context?
     * todo: split out input context?
     * todo: can i defined different context requirements?
     * todo: override definition? or abstract?
     */
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
