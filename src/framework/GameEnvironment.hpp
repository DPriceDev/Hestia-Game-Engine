#ifndef GAME_ENVIRONMENT_HPP
#define GAME_ENVIRONMENT_HPP

#include <vector>
#include <algorithm>

#include "InputController.hpp"
#include "../graphics/GraphicsController.hpp"
#include "Object.hpp"

#include "../sample/SampleTriangleObject.hpp"

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
     }

    /* Destructor */
    ~GameEnvironment() {
        for (auto& object: mObjects) {
            delete object;
        }
        delete mInputController;
        delete mGraphicsController;
    }

    /* Public Methods */
    void Init();
    void BeginGame();
    void GameLoop();
    void EndGame();

    void AddObject(Object* object);
    void RemoveObject(Object* object);
    Object* GetObject(long id);

    private:
    /* Private Variables */
    std::vector<Object*> mObjects;

    InputController* mInputController;
    GraphicsController* mGraphicsController;
};

#endif
