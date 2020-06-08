//
// Created by David Price on 16/05/2020.
//

#ifndef HESTIA_ROGUELIKE_DEPENDS_HGE_FRAMEWORK_SYSTEMS_DEBUG_SYSTEM_H
#define HESTIA_ROGUELIKE_DEPENDS_HGE_FRAMEWORK_SYSTEMS_DEBUG_SYSTEM_H

#define GLM_FORCE_SILENT_WARNINGS

#include <algorithm>
#include <glm/ext.hpp>
#include <glm/glm.hpp>
#include <vector>

#include "framework/ecs/component.h"
#include "framework/ecs/system.h"

#include "engine.h"
#include "maths/maths_types.h"

namespace HGE {

    struct Line {
        Vector2f mStart, mFinish;
        Pointf mWidth{};
        Pointf mPersistence{};
        ColourRGB mColour{255, 255, 255};

        Line() = default;
        Line(Vector2f start, Vector2f finish, Pointf width, Pointf persistence = 50.0f, ColourRGB colour = {255, 255, 255})
            : mStart(start), mFinish(finish), mWidth(width), mPersistence(persistence), mColour(colour) {}
    };

    struct Circle {
        Vector2f mCenter;
        Pointf mRadius{};
        Pointf mPersistence{};
        ColourRGB mColour{255, 255, 255};

        Circle() = default;
        Circle(Vector2f center, Pointf radius, Pointf persistence = 20.0f, ColourRGB colour = {255, 255, 255})
            : mCenter(center), mRadius(radius), mPersistence(persistence), mColour(colour) {}
    };

    /**
     * Debug Component
     */
    struct DebugComponent : public IComponent {
        std::vector<Line> mLines;
        std::vector<Circle> mCircles;

        explicit DebugComponent(UID ownerId) : IComponent(ownerId) {}
        ~DebugComponent() override = default;

        void drawLine(Vector2f &&start, Vector2f &&finish, Pointf &&width, ColourRGB &&colour) {
            mLines.emplace_back(start, finish, width, 20.0f, colour);
        }

        void drawCircle(Vector2f &&center, Pointf &&radius, Pointf &&width, ColourRGB &&colour) {
            mCircles.emplace_back(center, radius, width, colour);
        }
    };

    /**
     * Debug System
     * todo: refactor neater
     */
    template<>
    class System<DebugComponent> : public ISystem {
        ComponentArray<DebugComponent> *mDebugArray;
        std::vector<Line> mLines;
        std::vector<Circle> mCircles;
        Shader *mShader;

    public:
        explicit System(ComponentArray<DebugComponent> *debugArray) : mDebugArray(debugArray) {
            mShader = Engine::graphicsModule()->getShader("./assets/shaders/lineVertexShader.vs",
                                                          "./assets/shaders/lineFragmentShader.fs");
        }
        ~System() override = default;

        void run(const double &deltaTime) override {
            auto mCameraManager = Engine::cameraManager();
            auto mOrthographic = glm::ortho(mCameraManager->getViewportLeft(),
                                            mCameraManager->getViewportRight(),
                                            mCameraManager->getViewportBottom(),
                                            mCameraManager->getViewportTop());

            /* add new lines to draw from debug component */
            for (auto &component : mDebugArray->getComponents()) {
                mLines.insert(mLines.end(), component->mLines.begin(), component->mLines.end());
                mCircles.insert(mCircles.end(), component->mCircles.begin(), component->mCircles.end());
                component->mLines.clear();
                component->mCircles.clear();
            }

            /* draw lines and check if expired */
            int index = 0;
            auto toRemove = -1;
            for (auto &line : mLines) {
                Engine::graphicsModule()->drawLine(mShader, line.mStart, line.mFinish, line.mWidth, line.mColour,
                                                   mOrthographic);
                line.mPersistence -= deltaTime;

                if (line.mPersistence <= 0.0) {
                    toRemove = index;
                }
                ++index;
            }

            if (toRemove != -1) {
                mLines.erase(mLines.begin() + toRemove);
            }

            /* draw lines and check if expired */
            index = 0;
            toRemove = -1;
            for (auto &circle : mCircles) {
                Engine::graphicsModule()->drawCircle(mShader, circle.mCenter, circle.mRadius, 1.0f, circle.mColour,
                                                     mOrthographic);
                circle.mPersistence -= deltaTime;

                if (circle.mPersistence <= 0.0) {
                    toRemove = index;
                }
                ++index;
            }

            if (toRemove != -1) {
                mCircles.erase(mCircles.begin() + toRemove);
            }
        }
    };
}// namespace HGE

#endif//HESTIA_ROGUELIKE_DEPENDS_HGE_FRAMEWORK_SYSTEMS_DEBUG_SYSTEM_H
