#ifndef SAMPLE_TRIANGLE_OBJECT_HPP
#define SAMPLE_TRIANGLE_OBJECT_HPP

#include <iostream>
#include <vector>

#include "../framework/object.hpp"
#include "../graphics/viewable.hpp"

/**
 * 
 */
class SampleTriangleObject : public Object, public Viewable {

    private:

    public:
    SampleTriangleObject() {
        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
        };     
        mVertices.insert(mVertices.begin(), vertices, vertices+8);

        /* post shaders to graphics controller on creation. get shader numbers on return. */
    }

    ~SampleTriangleObject() {

    }

    void tick() override {
        std::cout << "ticking with id: " << getId() << std::endl;
    }

    void draw() override {
        std::cout << "drawing" << std::endl;

        /* draw object here using shaders and vertices. use vertex array. */
        //glBufferData(GL_ARRAY_BUFFER, sizeof(mVertices), mVertices, GL_STATIC_DRAW);

        // draw to local VAO. 
        // on render, the VAO is drawn by the graphics controller.
    }
};

#endif