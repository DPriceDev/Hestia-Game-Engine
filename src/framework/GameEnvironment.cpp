#include "framework/GameEnvironment.hpp"

#include "sample/SampleTriangleObject.hpp"
#include "framework/Engine.hpp"
#include "util/Logger.hpp"
#include <string>

#include "framework/ecs/System.hpp"
#include "framework/sprite/SpriteSystem.hpp"

namespace HGE {

    void HGE::GameEnvironment::Init() {
        //TODO: Replace with some sort of game instance config, load from file?
        Engine::getInstance()->getGraphicsModule()->setGameTitle("Hestia Game Engine v1.0-Alpha");

        auto start = Engine::getInstance()->getGraphicsModule()->getGameTime();

        Engine::getInstance()->getObjectManager()->CreateObject<SampleTriangleObject>();

        auto delta = Engine::getInstance()->getGraphicsModule()->getGameTime() - start;
        std::string time("Object Time" + std::to_string(delta));
        Logger::getInstance()->logDebug("Game Environment", time);
    }

    void HGE::GameEnvironment::GameLoop() { 
        Engine::getInstance()->getObjectManager()->tick();
        Engine::getInstance()->getGraphicsModule()->startFrame();
        Engine::getInstance()->getSystemManager()->run();
        Engine::getInstance()->getGraphicsModule()->renderFrame();
    }
}