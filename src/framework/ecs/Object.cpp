#include "framework/ecs/Object.hpp"

#include "framework/Engine.hpp"

namespace HGE {

    void Object::registerComponent(Component* component) {
        Engine::getInstance()->getComponentManager()->registerComponent(component);
    }
}