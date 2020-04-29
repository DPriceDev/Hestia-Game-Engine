#include "Engine.hpp"

/* */
bool HGE::Engine::Init(GraphicsModule* graphicsModule) {
    mGraphicsModule = graphicsModule;

    return mGraphicsModule->init();
}