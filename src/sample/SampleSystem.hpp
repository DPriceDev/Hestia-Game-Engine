#ifndef SAMPLE_SYSTEM_HPP_
#define SAMPLE_SYSTEM_HPP_

#include <iostream>
#include <vector>

#include "../framework/systems/system.hpp"

#include "../util/Logger.hpp"

/**
 * 
 */
class SampleSystem : public System {

    public:
    SampleSystem() {
        LogDebug("Sample System Created");
    }

    ~SampleSystem() {
        
    }
};

#endif