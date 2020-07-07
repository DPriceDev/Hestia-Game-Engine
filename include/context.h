//
// Created by David Price on 07/07/2020.
//

#ifndef HESTIA_GAME_ENGINE_INCLUDE_CONTEXT_H
#define HESTIA_GAME_ENGINE_INCLUDE_CONTEXT_H

namespace HGE {
    class ObjectManager;
    class ComponentManager;
    class SystemManager;

    struct Context {
        ObjectManager* mObjectManager;
        ComponentManager* mComponentManager;
        SystemManager *mSystemManager;

        Context() : mObjectManager(nullptr),
                    mComponentManager(nullptr),
                    mSystemManager(nullptr) { }
    };
}

#endif //HESTIA_GAME_ENGINE_INCLUDE_CONTEXT_H
