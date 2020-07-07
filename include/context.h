//
// Created by David Price on 07/07/2020.
//

#ifndef HESTIA_GAME_ENGINE_INCLUDE_CONTEXT_H
#define HESTIA_GAME_ENGINE_INCLUDE_CONTEXT_H

namespace HGE {
    class ObjectManager;
    class ComponentManager;

    struct Context {
        ObjectManager* mObjectManager;
        ComponentManager* mComponentManager;

        Context() : mObjectManager(nullptr), mComponentManager(nullptr) { }
        Context(ObjectManager* objectManager, ComponentManager* componentManager)
            : mObjectManager(objectManager), mComponentManager(componentManager) { }
    };
};

#endif//HESTIA_GAME_ENGINE_INCLUDE_CONTEXT_H
