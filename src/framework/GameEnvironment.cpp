#include "framework/GameEnvironment.hpp"

#include "sample/SampleTriangleObject.hpp"

#include "framework/Engine.hpp"

namespace HGE {

    void HGE::GameEnvironment::Init() {
        //TODO: Replace with some sort of game instance config, load from file?
        Engine::getInstance()->getGraphicsModule()->setGameTitle("Hestia Game Engine v1.0-Alpha");

        for(int i = 0; i < 10; i++) {
            Engine::getInstance()->getObjectManager()->CreateObject<SampleTriangleObject>();
        }
    }

    void HGE::GameEnvironment::GameLoop() { 
        Engine::getInstance()->getObjectManager()->tick();
        Engine::getInstance()->getGraphicsModule()->startFrame();
        Engine::getInstance()->getSystemManager()->run();
        Engine::getInstance()->getGraphicsModule()->renderFrame();
    }

}