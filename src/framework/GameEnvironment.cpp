#include "framework/GameEnvironment.h"

#include <string>

#include "framework/Engine.h"

#include "sample/SampleTriangleObject.h"

#include "util/Logger.h"

namespace HGE {

    void HGE::GameEnvironment::Init() {
        //TODO: Replace with some sort of game instance config, load from file?
        Engine::instance()->graphicsModule()->setGameTitle("Hestia Game Engine v1.0-Alpha");

        auto start = Engine::instance()->graphicsModule()->getGameTime();
        for(int i = 0; i < 1; ++i) {
            Engine::instance()->objectManager()->CreateObject<SampleTriangleObject>();
        }
        auto delta = Engine::instance()->graphicsModule()->getGameTime() - start;
        //std::string time("Object Time: " + std::to_string(delta));
        Logger::instance()->logDebug("Game Environment", "Object time:", delta);
    }

    void HGE::GameEnvironment::GameLoop() { 
        Engine::instance()->objectManager()->tick();
        Engine::instance()->graphicsModule()->startFrame();
        Engine::instance()->systemManager()->run();
        Engine::instance()->graphicsModule()->renderFrame();
    }
}