#include "GameEnvironment.hpp"

#include "../src/sample/SampleTriangleObject.hpp"

#include "Engine.hpp"

namespace HGE {

    void HGE::GameEnvironment::Init() {
        //TODO: Replace with some sort of game instance config, load from file?
        Engine::getInstance()->getGraphicsModule()->setGameTitle("Hestia Game Engine v1.0-Alpha");
        Engine::getInstance()->getObjectManager()->CreateObject<SampleTriangleObject>();
    }

    void HGE::GameEnvironment::GameLoop() { 
        Engine::getInstance()->getObjectManager()->tick();
        Engine::getInstance()->getGraphicsModule()->startFrame();
        Engine::getInstance()->getSystemManager()->run();
        Engine::getInstance()->getGraphicsModule()->renderFrame();
    }

}