#ifndef HESTIA_FRAMEWORK_GAME_ENVIRONMENT_H
#define HESTIA_FRAMEWORK_GAME_ENVIRONMENT_H

namespace HGE {
    
    class GameEnvironment
    {
        public:
        GameEnvironment() { }
        ~GameEnvironment() { }

        /* Public Methods */
        void Init();
        void BeginGame();
        void GameLoop();
        void EndGame();
    };
}

#endif
