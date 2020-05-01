#include "framework/Engine.hpp"

using namespace HGE;

/* */
bool HGE::Engine::Init(GraphicsModule* graphicsModule) {
    mGraphicsModule = graphicsModule;

    return mGraphicsModule->init();
}