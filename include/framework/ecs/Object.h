#ifndef HESTIA_FRAMEWORK_ECS_OBJECT_H
#define HESTIA_FRAMEWORK_ECS_OBJECT_H

#include <tuple>
#include <vector>
#include <memory>

#include "framework/ecs/ComponentManager.h"
#include "framework/ecs/IComponent.h"
#include "util/Uid.h"
#include "util/Logger.h"


namespace HGE {
    using UID = int;

    /**
     * Object Interface
     */
    class IObject {
        public:
        UID id;
        virtual ~IObject() = default;
        virtual UID getId() const = 0;
        virtual void onCreate() = 0;
    };

    /**
     * Object Templated Class
     */
//    template <typename Cs>
    class Object : public IObject {
        UID id = GenerateUniqueId();

        // template<typename C, typename... Css>
        // void createComponents(ComponentManager* componentManager) {
        //     std::get<C*>(mComponents) = componentManager->createComponent<C>(id);
        //     createComponents<Css...>();
        // }

        // template<typename C>
        // void createComponents(ComponentManager* componentManager) {
        //     std::get<C*>(mComponents) = componentManager->createComponent<C>(id);
        // }

        // protected:
        // std::tuple<Cs*> mComponents;

        public:
        Object() = default;
        ~Object() override = default;

        /* Setters and Getters */
        UID getId() const override {
            return id;
        }

        /* Public Methods */
        void onCreate() override = 0;
    };
}

#endif