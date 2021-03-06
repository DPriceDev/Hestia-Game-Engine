//
// Created by David Price on 07/07/2020.
//

#include "camera/camera_manager.h"
#include "catch.hpp"
#include <graphics/opengl_module.h>

TEST_CASE("") {
    auto mockGraphicsModule = std::make_unique<HGE::OpenglModule>();

    HGE::CameraManager cameraManager(static_cast<HGE::GraphicsModule *>(mockGraphicsModule.get()));
}