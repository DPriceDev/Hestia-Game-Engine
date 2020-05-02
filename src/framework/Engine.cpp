#include "framework/Engine.hpp"

using namespace HGE;

/* */
bool Engine::Init(std::unique_ptr<GraphicsModule> graphicsModule) {
    mGraphicsModule.swap(graphicsModule);
    graphicsModule.release();
    return mGraphicsModule->init();
}