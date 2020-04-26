#ifndef SAMPLE_TRIANGLE_OBJECT_HPP
#define SAMPLE_TRIANGLE_OBJECT_HPP

#include <iostream>
#include <vector>

#include "../src/framework/ecs/object.hpp"
#include "../src/framework/graphics/GraphicsComponent.hpp"
#include "SampleComponent.hpp"

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

        auto mGraphicsComponent = new GraphicsComponent();
        registerComponent(mGraphicsComponent);

        SampleComponent* componentTwo = new SampleComponent();
        registerComponent(componentTwo);
    }

    // TODO: Maybe move this to a component too? could reduce redundant calls? move all game loops to systems?
    void tick() override {
        //std::cout << "ticking with id: " << getId() << std::endl;
    }
};

#endif