#include "input/InputManager.hpp"

#include "framework/Engine.hpp"

using namespace HGE;

InputManager::InputManager() {

}

InputManager::~InputManager() {
    
}

bool InputManager::getKeyValue(KeyType key) {
    return Engine::getInstance()->getGraphicsModule()->getKeyValue(key);
}

// /* Process Input */
// void InputController::processInput(GLFWwindow *window) {
//     if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//     glfwSetWindowShouldClose(window, true);
// }