#include "GameEnvironment.hpp"

/**
 * 
 */
void GameEnvironment::Init() {
    //TODO: Replace with some sort of game instance config, load from file?
    AddObject(new SampleTriangleObject());
}

/**
 * 
 */
void GameEnvironment::GameLoop() {
    for(auto & object : mObjects) {
        object->tick();
    }
}

void GameEnvironment::AddObject(Object* object) {
    auto it = std::find(mObjects.begin(), mObjects.end(), object);

    if(it == mObjects.end()) {
        mObjects.push_back(object);

        if (Viewable* viewable = dynamic_cast<Viewable*>(object)) {
            mGraphicsController->AddViewable(viewable);
        }
    }
}

void GameEnvironment::RemoveObject(Object* object) {
    auto it = std::find(mObjects.begin(), mObjects.end(), object);

    if(it != mObjects.end()) {
        mObjects.erase(it);

        if (Viewable* viewable = dynamic_cast<Viewable*>(object)) {
            mGraphicsController->RemoveViewable(viewable);
        }
    }
}

Object* GameEnvironment::GetObject(long id) {

}