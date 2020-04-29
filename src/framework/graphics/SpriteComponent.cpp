#include "SpriteComponent.hpp"

#include "../src/framework/Engine.hpp"

#include "SpriteSystem.hpp"

namespace HGE {

    void SpriteComponent::registerSystem() {
            Engine::getInstance()->getSystemManager()->registerSystem<SpriteSystem>();    
    }
}