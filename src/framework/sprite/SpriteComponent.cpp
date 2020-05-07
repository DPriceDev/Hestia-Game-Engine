#include "framework/sprite/SpriteComponent.hpp"
#include "framework/Engine.hpp"
#include "framework/sprite/SpriteSystem.hpp"

using namespace HGE;

/* init with default shader and material! */
SpriteComponent::SpriteComponent(UID ownerId) : Component(ownerId), mTransform(Transform2f()), mTint(ColourRGBA()), mAlpha(1.0f) {
    //Engine::getInstance()->getSystemManager()->registerComponent<SpriteComponent>(this);  
}

SpriteComponent::~SpriteComponent() { 
    //Engine::getInstance()->getSystemManager()->deregisterComponent<SpriteComponent>(this);  
 }

void SpriteComponent::registerSystem() {
    //Engine::getInstance()->getSystemManager()->registerComponent<SpriteComponent>(this);    
}