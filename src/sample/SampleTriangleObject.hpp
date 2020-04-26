#ifndef SAMPLE_TRIANGLE_OBJECT_HPP
#define SAMPLE_TRIANGLE_OBJECT_HPP

#include <iostream>
#include <vector>

#include "../framework/objects/object.hpp"
#include "sampleComponent.hpp"

#include "../util/Logger.hpp"

/**
 * 
 */
class SampleTriangleObject : public Object {

    private:

    public:
    SampleTriangleObject() { }

    ~SampleTriangleObject() {

    }

    void onCreate() override {
        LogDebug("Sample triangle Created");

        SampleComponent* component = new SampleComponent();
        registerComponent(component);

        SampleComponent* componentTwo = new SampleComponent();
        registerComponent(componentTwo);
    }

    void tick() override {
        //std::cout << "ticking with id: " << getId() << std::endl;
    }
};

#endif