#include "framework/Engine.h"

namespace HGE {

    bool Engine::Init(std::unique_ptr<GraphicsModule> graphicsModule) {
        mGraphicsModule.swap(graphicsModule);
        graphicsModule.release();
        return mGraphicsModule->init();
    }
}