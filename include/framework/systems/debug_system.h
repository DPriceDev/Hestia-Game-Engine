//
// Created by David Price on 16/05/2020.
//

#ifndef HESTIA_ROGUELIKE_DEPENDS_HGE_FRAMEWORK_SYSTEMS_DEBUG_SYSTEM_H
#define HESTIA_ROGUELIKE_DEPENDS_HGE_FRAMEWORK_SYSTEMS_DEBUG_SYSTEM_H

#include <vector>
#include <algorithm>
#include <glm/glm/glm.hpp>
#include <glm/glm/ext.hpp>

#include "framework/ecs/component.h"
#include "framework/ecs/system.h"

#include "engine.h"
#include "maths/maths_types.h"

namespace HGE {

    struct Line {
        Vector2f mStart, mFinish;
        Pointf mWidth{ };
        Pointf mPersistence{ };
        ColourRGB mColour{ 255, 255, 255 };

        Line() = default;
        Line(Vector2f start, Vector2f finish, Pointf width, Pointf persistence = 1.0f, ColourRGB colour = { 255, 255, 255 })
            : mStart(start), mFinish(finish), mWidth(width), mPersistence(persistence), mColour(colour)  { }
    };

    /**
     * Debug Component
     */
    struct DebugComponent : public IComponent {
        std::vector<Line> mLines;

        explicit DebugComponent(UID ownerId) : IComponent(ownerId) { }
        ~DebugComponent() override = default;

        void drawLine(Vector2f&& start, Vector2f&& finish, Pointf&& width) {
            mLines.emplace_back(start, finish, width);
        }
    };

    /**
     * Debug System
     * todo: refactor neater
     */
    template <>
    class System<DebugComponent> : public ISystem {
        ComponentArray<DebugComponent>* mDebugArray;
        std::vector<Line> mLines;
        Shader* mShader;

    public:
        explicit System(ComponentArray<DebugComponent>* debugArray) : mDebugArray(debugArray) {
            mShader = Engine::graphicsModule()->getShader("./assets/shaders/lineVertexShader.vs",
                                                          "./assets/shaders/lineFragmentShader.fs");
        }
        ~System() override = default;

        void run(const double& deltaTime) override {
            auto mCameraManager = Engine::cameraManager();
            auto mOrthographic = glm::ortho(mCameraManager->getViewportLeft(),
                                       mCameraManager->getViewportRight(),
                                       mCameraManager->getViewportBottom(),
                                       mCameraManager->getViewportTop());

            for(auto & component : mDebugArray->getComponents()) {
                mLines.insert(mLines.end(), component->mLines.begin(), component->mLines.end());
                component->mLines.clear();
            }

            int index = 0;
            for(auto & line : mLines) {
                Engine::graphicsModule()->drawLine(mShader, line.mStart, line.mFinish, line.mWidth, line.mColour,
                        mOrthographic);
                line.mPersistence -= deltaTime;

                if(line.mPersistence <= 0.0) {
                    mLines.erase(mLines.begin() + index);
                }
                ++index;
            }
        }
    };
}

#endif //HESTIA_ROGUELIKE_DEPENDS_HGE_FRAMEWORK_SYSTEMS_DEBUG_SYSTEM_H
