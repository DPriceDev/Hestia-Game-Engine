#ifndef HESTIA_FRAMEWORK_GAME_ENVIRONMENT_H
#define HESTIA_FRAMEWORK_GAME_ENVIRONMENT_H

#include <memory>

#include <framework/ecs/ObjectManager.h>

namespace HGE {
    
    class GameEnvironment {
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

        template<class GM>
        static GM build(ObjectManager* objectManager) {
            auto gm = GM();
            gm.mObjectManager = objectManager;
            return gm;
        }

        template<class GM>
        static std::unique_ptr<GM> buildUnique(ObjectManager* objectManager) {
            auto gm = std::make_unique<GM>();
            gm->mObjectManager = objectManager;
            return std::move(gm);
        }
    };
}

#endif
