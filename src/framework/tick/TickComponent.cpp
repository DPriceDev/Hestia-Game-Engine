#include "TickComponent.hpp"

#include "../src/framework/Engine.hpp"

#include "TickSystem.hpp"

namespace HGE {

        void TickComponent::registerSystem() {
                Engine::getInstance()->getSystemManager()->registerSystem<TickSystem>();
        }
}