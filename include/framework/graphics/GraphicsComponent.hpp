#ifndef HESTIA_GRAPHICS_GRAPHICSCOMPONENT_HPP_
#define HESTIA_GRAPHICS_GRAPHICSCOMPONENT_HPP_

#include <iostream>
#include <vector>

#include "framework/ecs/Component.hpp"

#include "maths/MathsTypes.hpp"
#include "graphics/Shader.hpp"

#include "util/Logger.hpp"

namespace HGE {

    struct GraphicsComponent : public Component {
        
        public:
        GraphicsComponent() : Component("Graphics") {
            LogDebug("Graphics Component", "Created");
            mVertices = std::vector<Vector2f>();
        }

        ~GraphicsComponent() { }

        std::vector<Vector2f> mVertices;
        Shader* mShader;
        unsigned int mVAO, mVBO;

        std::vector<Vector2f>* getVerticesPointer() {
            return &mVertices;
        }

        void registerSystem() override;
    };
}

#endif