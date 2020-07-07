//
// Created by David Price on 14/05/2020.
//

#ifndef HESTIA_FRAMEWORK_GAME_OBJECT_H
#define HESTIA_FRAMEWORK_GAME_OBJECT_H

#include "ecs_facade.h"
#include "object.h"
#include "context.h"

namespace HGE {

    class GameObject : public IObject, public EcsFacade {
        Context* mContext;

    public:
        GameObject(Context* context) : EcsFacade(context), mContext(context) {}
        ~GameObject() override = default;

        /* Public Methods */
        void onCreate() override = 0;
    };
}// namespace HGE

#endif//HESTIA_FRAMEWORK_GAME_OBJECT_H
