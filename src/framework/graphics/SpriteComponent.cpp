#include "framework/graphics/SpriteComponent.hpp"
#include "framework/Engine.hpp"
#include "framework/graphics/SpriteSystem.hpp"

using namespace HGE;

void SpriteComponent::registerSystem() {
        Engine::getInstance()->getSystemManager()->registerSystem<SpriteSystem>();    
}

// void SpriteComponent::setWidth(float width) {
//     mVertices[0] = -width/2;
//     mVertices[2] = width/2;
//     mVertices[4] = -width/2;
//     mVertices[6] = width/2;
// }

// void SpriteComponent::setHeight(float height) {
//     mVertices[1] = height/2;
//     mVertices[3] = height/2;
//     mVertices[5] = -height/2;
//     mVertices[7] = -height/2;
// }

// void SpriteComponent::setWidthAndHeight(float width, float height) {
//     setWidth(width);
//     setHeight(height);
// }
