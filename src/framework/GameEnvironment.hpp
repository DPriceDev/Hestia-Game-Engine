#ifndef HESTIA_FRAMEWORK_GAME_ENVIRONMENT_HPP_
#define HESTIA_FRAMEWORK_GAME_ENVIRONMENT_HPP_

/**
 * Object Controller
 */
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

#endif
