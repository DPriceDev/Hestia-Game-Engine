#include "Object.hpp"

#include "../src/framework/Engine.hpp"

void Object::registerComponent(Component* component) {
    Engine::getInstance()->getComponentManager()->registerComponent(component);
}