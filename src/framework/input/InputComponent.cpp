#include "framework/input/InputComponent.hpp"
#include "framework/Engine.hpp"
#include "framework/input/InputSystem.hpp"

using namespace HGE;

void InputComponent::registerSystem() {
    Engine::getInstance()->getSystemManager()->registerSystem<InputSystem>();
}