#include "sample/SampleComponent.hpp"

#include "framework/Engine.hpp"

#include "sample/SampleSystem.hpp"

void SampleComponent::registerSystem() {
        HGE::Engine::getInstance()->getSystemManager()->registerSystem<SampleSystem>();
}