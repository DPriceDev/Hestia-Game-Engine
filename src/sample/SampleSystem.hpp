#ifndef SAMPLE_SYSTEM_HPP_
#define SAMPLE_SYSTEM_HPP_

#include <iostream>
#include <vector>

#include "../src/framework/ecs/System.hpp"
#include "../src/framework/ecs/Component.hpp"

#include "../util/Logger.hpp"

#include "SampleComponent.hpp"

class SampleSystem : public HGE::System {

    public:
    SampleSystem() {
        LogDebug("Sample System Created");
        mComponentArray = HGE::Engine::getInstance()->getComponentManager()->getComponentArray<SampleComponent>();
    }

    ~SampleSystem() {
    }

    void run() override {
        for(auto & component : *mComponentArray) {
            // SampleComponent* sampleComponent = dynamic_cast<SampleComponent*>(component);
        }
    }
};

#endif