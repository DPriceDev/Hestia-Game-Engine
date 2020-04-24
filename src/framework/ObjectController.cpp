#include "ObjectController.hpp"

/**
 *  Add Game Object
 */
void ObjectController::AddGameObject(Object* object) {
    mObjects->push_back(object);
}

/**
 *  Get Game Object by index.
 */
Object* ObjectController::GetGameObject(int index) {
    if(index >= 0 && index <= mObjects->size() - 1) {
        return mObjects->at(index);
    } else {
        return nullptr;
    }
}

/**
 *  Delete Game Object
 */
void ObjectController::DeleteGameObject(Object* object) {
    auto it = std::find(mObjects->begin(), mObjects->end(), object);
    if(it != mObjects->end()) {
        mObjects->erase(it);
    }
}