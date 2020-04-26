#ifndef SAMPLE_COMPONENT_HPP
#define SAMPLE_COMPONENT_HPP

#include <iostream>
#include <vector>

#include "../framework/components/Component.hpp"

#include "../util/Logger.hpp"

/**
 * 
 */
class SampleComponent : public Component {

    public:
    SampleComponent() : Component("Sample") {
        LogDebug("Sample Component Created");
    }

    ~SampleComponent() {
        
    }

    void registerSystem();
};

#endif