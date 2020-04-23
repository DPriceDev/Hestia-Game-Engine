#ifndef OBJECT_CONTROLLER_HPP
#define OBJECT_CONTROLLER_HPP

#include <vector>
#include <algorithm>

#include "Object.hpp"

/**
 * Object Controller
 */
class ObjectController
{
    public:
    /* Constructor */
    ObjectController() {
        gameObjects = std::vector<Object*>();
     }

    /* Destructor */
    ~ObjectController() { 
        gameObjects.clear();
    }

    /* Public Methods */
    void addGameObject(Object* object);

    Object* getGameObject(int index);

    void deleteGameObject(Object* object);

    //std::vector<Object*> findObjectsByClass();

    private:
    std::vector<Object*> gameObjects;
};

#endif