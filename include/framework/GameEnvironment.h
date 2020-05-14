#ifndef HESTIA_FRAMEWORK_GAME_ENVIRONMENT_H
#define HESTIA_FRAMEWORK_GAME_ENVIRONMENT_H

#include <memory>

#include "framework/ecs/ECSFacade.h"
#include "framework/ecs/ObjectManager.h"

namespace HGE {

    class GameEnvironment : public EcsFacade {

    public:
        GameEnvironment() : EcsFacade() { }
        virtual ~GameEnvironment() = default;

        /* Public Methods */
        virtual void beginGame() = 0;
        virtual void gameLoop(const double & deltaTime) = 0;
        virtual void endGame() = 0;
    };

    template<typename G>
    concept game_environment = std::is_base_of<GameEnvironment, G>::value;
}

#endif
