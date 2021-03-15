#ifndef HESTIA_FRAMEWORK_GAME_ENVIRONMENT_H
#define HESTIA_FRAMEWORK_GAME_ENVIRONMENT_H

#include <memory>

#include "context.h"

namespace HGE {

    /**
     * Game Environment
     * Takes a context to pass to the ECS facade
     * todo: Renamed to game session?
     */
    class GameEnvironment {
    protected:
        Context* mContext;

    public:
        /* RAII */
        explicit GameEnvironment(Context* context) : mContext(context) {}

        virtual ~GameEnvironment() = default;

        /* Called at the beginning of this game session */
        virtual void beginGame() = 0;

        /* Runs continuously during the game session */
        virtual void gameLoop(const double &deltaTime) = 0;

        /* Called when the game session ends */
        virtual void endGame() = 0;
    };

    // todo: Concept defines this as a better template parameter
    //    template<typename G>
    //    concept game_environment = std::is_base_of<GameEnvironment, G>::value;
}// namespace HGE

#endif
