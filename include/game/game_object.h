//
// Created by David Price on 14/05/2020.
//

#ifndef HESTIA_FRAMEWORK_GAME_OBJECT_H
#define HESTIA_FRAMEWORK_GAME_OBJECT_H

#include "context.h"
#include "framework/ecs/object.h"

namespace HGE {

    /**
     * Game Object Class
     * Provides a solid interface for an in game object.
     * This class extends "EcsFacade" which provides methods to create and destroy objects and components.
     */
    class GameObject : public IObject {
    protected:
        Context* mContext;

    public:
        /* RAII */
        GameObject(Context* context) : mContext(context) {}

        ~GameObject() override = default;

        /* on Create Object */
        void onCreate() override = 0;
    };
}// namespace HGE

#endif //HESTIA_FRAMEWORK_GAME_OBJECT_H
