#include "framework/tick/TickComponent.hpp"

#include "framework/Engine.hpp"

#include "framework/tick/TickSystem.hpp"

namespace HGE {

        void TickComponent::registerSystem() {
                Engine::getInstance()->getSystemManager()->registerSystem<TickSystem>();
        }
}