#include "framework/sprite/SpriteComponent.hpp"
#include "framework/Engine.hpp"
#include "framework/sprite/SpriteSystem.hpp"

using namespace HGE;

void SpriteComponent::registerSystem() {
        Engine::getInstance()->getSystemManager()->registerSystem<SpriteSystem>();    
}