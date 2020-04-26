#ifndef SAMPLE_COMPONENT_HPP
#define SAMPLE_COMPONENT_HPP

#include <iostream>
#include <vector>

#include "../framework/ecs/Component.hpp"

#include "../util/Logger.hpp"

/**
 * 
 */
struct SampleComponent : public Component {

    public:
    SampleComponent() : Component("Sample") {
        LogDebug("Sample Component Created");
    }

    int value = 5;

    ~SampleComponent() {
        
    }

    void registerSystem() override;
};

#endif