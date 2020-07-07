#ifndef HESTIA_FRAMEWORK_GAME_ENVIRONMENT_H
#define HESTIA_FRAMEWORK_GAME_ENVIRONMENT_H

#include <memory>

#include "framework/ecs/ecs_facade.h"
#include "context.h"

namespace HGE {

    class GameEnvironment : public EcsFacade {
    Context* mContext;

    public:
        GameEnvironment(Context* context) : EcsFacade(context), mContext(context) {}
        virtual ~GameEnvironment() = default;

        /* Public Methods */
        virtual void beginGame() = 0;
        virtual void gameLoop(const double &deltaTime) = 0;
        virtual void endGame() = 0;
    };

    //    template<typename G>
    //    concept game_environment = std::is_base_of<GameEnvironment, G>::value;
}// namespace HGE

#endif
