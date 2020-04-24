#ifndef GAME_ENVIRONMENT_HPP
#define GAME_ENVIRONMENT_HPP

#include <vector>

#include "ObjectController.hpp"
#include "InputController.hpp"
#include "../graphics/GraphicsController.hpp"
#include "Object.hpp"

/**
 * Object Controller
 */
class GameEnvironment
{
    public:
    /* Constructor */
    GameEnvironment(InputController* InputController, GraphicsController* graphicsController)
                    : mInputController(InputController), 
                     mGraphicsController(graphicsController) {
        mObjects = std::vector<Object*>();
        mObjectController = new ObjectController(&mObjects);
     }

    /* Destructor */
    ~GameEnvironment() {
        for (auto& object: mObjects) {
            delete object;
        }
        delete mObjectController;
        delete mInputController;
        delete mGraphicsController;
    }

    /* Public Methods */
    void BeginGame();
    void GameLoop();
    void EndGame();

    private:
    /* Private Variables */
    std::vector<Object*> mObjects;

    ObjectController* mObjectController;
    InputController* mInputController;
    GraphicsController* mGraphicsController;
};

#endif
