#ifndef SAMPLE_SYSTEM_HPP_
#define SAMPLE_SYSTEM_HPP_

#include <iostream>
#include <vector>

#include "../framework/systems/system.hpp"
#include "../framework/components/Component.hpp"

#include "../util/Logger.hpp"

#include "sampleComponent.hpp"

/**
 * 
 */
class SampleSystem : public System {

    private:
    std::vector<Component*>* mComponents; 

    public:
    SampleSystem() {
        LogDebug("Sample System Created");
        mComponents = Engine::getInstance()->getComponentManager()->getComponentArray<SampleComponent>();
    }

    ~SampleSystem() {
    }


};

#endif