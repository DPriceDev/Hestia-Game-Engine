#include "framework/input/InputSystem.hpp"

#include "framework/Engine.hpp"
#include "framework/input/InputComponent.hpp"

#include "util/Logger.hpp"

using namespace HGE;

InputSystem::InputSystem() {
    //std::get<std::vector<std::unique_ptr<InputComponent>>>(mComponents) = std::vector<std::unique_ptr<InputComponent>>();
    mInputManager = Engine::getInstance()->getInputManager();
    Logger::getInstance()->logDebug("Input System", "Created");
}

InputSystem::~InputSystem() {

}

void InputSystem::run() {
    //InputComponent* inputComponent;

    // for(auto & component : std::get<std::vector<std::unique_ptr<InputComponent>>>(mComponents)) {

    //     for( auto & [key, val] : component->mKeys ) {
    //         val = mInputManager->getKeyValue(key);
    //     }
    // }
}