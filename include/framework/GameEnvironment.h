#ifndef HESTIA_FRAMEWORK_GAME_ENVIRONMENT_H
#define HESTIA_FRAMEWORK_GAME_ENVIRONMENT_H

namespace HGE {
    
    class GameEnvironment
    {
        public:
        virtual ~GameEnvironment() = default;

        /* Public Methods */
        virtual void beginGame() = 0;
        virtual void gameLoop() = 0;
        virtual void endGame() = 0;
    };
}

#endif
