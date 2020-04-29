#include "Object.hpp"

#include "../src/framework/Engine.hpp"

namespace HGE {

    void Object::registerComponent(Component* component) {
        Engine::getInstance()->getComponentManager()->registerComponent(component);
    }
}