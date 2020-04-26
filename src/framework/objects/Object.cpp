#include "Object.hpp"

#include "../src/framework/Engine.hpp"

Object* Object::registerComponent(Component* component) {
    Engine::getInstance()->getComponentManager()->registerComponent(component);
}