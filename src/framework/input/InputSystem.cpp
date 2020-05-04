#include "framework/input/InputSystem.hpp"

#include "framework/Engine.hpp"
#include "framework/input/InputComponent.hpp"

#include "util/Logger.hpp"

using namespace HGE;

InputSystem::InputSystem() {
    Logger::getInstance()->logDebug("Graphics System", "Created");
    mComponents = Engine::getInstance()->getComponentManager()->getComponentArray<InputComponent>();
    mInputManager = Engine::getInstance()->getInputManager();
}

InputSystem::~InputSystem() {

}

void InputSystem::run() {
    InputComponent* inputComponent;

    for(auto & component : *mComponents) {
        inputComponent = dynamic_cast<InputComponent*>(component);

        for( auto & [key, val] : inputComponent->mKeys ) {
            val = mInputManager->getKeyValue(key);
        }
    }
}