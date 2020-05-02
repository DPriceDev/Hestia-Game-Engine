#ifndef SAMPLE_SYSTEM_HPP_
#define SAMPLE_SYSTEM_HPP_

#include <iostream>
#include <vector>

#include "framework/ecs/System.hpp"
#include "framework/ecs/Component.hpp"

#include "util/Logger.hpp"

#include "sample/SampleComponent.hpp"

class SampleSystem : public HGE::System {

    public:
    SampleSystem() {
        HGE::Logger::getInstance()->logDebug("Sample System", "Created");
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