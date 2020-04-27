#include "Engine.hpp"

/* */
bool Engine::Init(GraphicsModule* graphicsModule) {
    mGraphicsModule = graphicsModule;

    return mGraphicsModule->init();
}