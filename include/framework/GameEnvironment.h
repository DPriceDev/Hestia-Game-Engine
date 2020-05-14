#ifndef HESTIA_FRAMEWORK_GAME_ENVIRONMENT_H
#define HESTIA_FRAMEWORK_GAME_ENVIRONMENT_H

#include <memory>

#include "framework/ecs/ObjectManager.h"

namespace HGE {

    class GameEnvironment {
        friend class Engine;
        ObjectManager* mObjectManager = nullptr;

    public:
        GameEnvironment() = default;
        virtual ~GameEnvironment() = default;

        /* Public Methods */
        virtual void beginGame() = 0;
        virtual void gameLoop(const double & deltaTime) = 0;
        virtual void endGame() = 0;

        template<class Obj>
        const Obj* createObject() const { return mObjectManager->CreateObject<Obj>(); }
    };
}

#endif
