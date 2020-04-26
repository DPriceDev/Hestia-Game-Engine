#ifndef SAMPLE_SYSTEM_HPP_
#define SAMPLE_SYSTEM_HPP_

#include <iostream>
#include <vector>

#include "../src/framework/ecs/system.hpp"
#include "../src/framework/ecs/Component.hpp"

#include "../util/Logger.hpp"

#include "SampleComponent.hpp"

/**
 * 
 */
class SampleSystem : public System {

    public:
    SampleSystem() {
        LogDebug("Sample System Created");
        mComponentArray = Engine::getInstance()->getComponentManager()->getComponentArray<SampleComponent>();
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