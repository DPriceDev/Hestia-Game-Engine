#ifndef SAMPLE_TRIANGLE_OBJECT_HPP
#define SAMPLE_TRIANGLE_OBJECT_HPP

#include <iostream>
#include <vector>

#include "../framework/objects/object.hpp"

#include "../util/Logger.hpp"

/**
 * 
 */
class SampleTriangleObject : public Object {

    private:

    public:
    SampleTriangleObject() {
        LogDebug("Sample triangle Created");
    }

    ~SampleTriangleObject() {

    }

    void tick() override {
        //std::cout << "ticking with id: " << getId() << std::endl;
    }
};

#endif