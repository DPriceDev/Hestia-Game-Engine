//
// Created by David Price on 14/05/2020.
//

#ifndef HESTIA_FRAMEWORK_GAME_OBJECT_H
#define HESTIA_FRAMEWORK_GAME_OBJECT_H

#include "object.h"
#include "ecs_facade.h"

namespace HGE {

    class GameObject : public IObject, public EcsFacade {
    public:
        GameObject() : EcsFacade() { }
        ~GameObject() override = default;

        /* Public Methods */
        void onCreate() override = 0;
    };
}

#endif //HESTIA_FRAMEWORK_GAME_OBJECT_H
