#include "SampleComponent.hpp"

#include "../framework/Engine.hpp"

#include "SampleSystem.hpp"

void SampleComponent::registerSystem() {
        HGE::Engine::getInstance()->getSystemManager()->registerSystem<SampleSystem>();
}