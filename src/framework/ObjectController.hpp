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
    ObjectController(std::vector<Object*>* objects) : mObjects(objects) { }

    /* Destructor */
    ~ObjectController() { 
        delete mObjects;
    }

    /* Public Methods */
    void AddGameObject(Object* object);

    Object* GetGameObject(int index);

    void DeleteGameObject(Object* object);

    //std::vector<Object*> FindObjectsByClass();

    private:
    std::vector<Object*>* mObjects;
};

#endif