#include "framework/GameEnvironment.h"

#include <string>

#include "framework/Engine.h"
#include "framework/ecs/ecs.h"

#include "sample/SampleTriangleObject.h"

#include "util/Logger.h"

namespace HGE {

    void HGE::GameEnvironment::Init() {
        //TODO: Replace with some sort of game instance config, load from file?
        Engine::getInstance()->getGraphicsModule()->setGameTitle("Hestia Game Engine v1.0-Alpha");

        auto start = Engine::getInstance()->getGraphicsModule()->getGameTime();
        for(int i = 0; i < 2; ++i) {
            Engine::getInstance()->getObjectManager()->CreateObject<SampleTriangleObject>();
        }
        auto delta = Engine::getInstance()->getGraphicsModule()->getGameTime() - start;
        std::string time("Object Time: " + std::to_string(delta));
        Logger::getInstance()->logDebug("Game Environment", time);
    }

    void HGE::GameEnvironment::GameLoop() { 
        Engine::getInstance()->getObjectManager()->tick();
        Engine::getInstance()->getGraphicsModule()->startFrame();
        Engine::getInstance()->getSystemManager()->run();
        Engine::getInstance()->getGraphicsModule()->renderFrame();
    }
}