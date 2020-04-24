#ifndef SAMPLE_TRIANGLE_OBJECT_HPP
#define SAMPLE_TRIANGLE_OBJECT_HPP

#include <iostream>

#include "../framework/object.hpp"
#include "../graphics/viewable.hpp"

/**
 * 
 */
class SampleTriangleObject : public Object, public Viewable {

    int index = 0;

    void tick() override {
        std::cout << "ticking" << std::endl;
    }

    void draw() override {
        std::cout << "drawing" << std::endl;
    }
};

#endif