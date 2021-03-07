cmake_minimum_required(VERSION 3.5)

add_library(hestia_catch_main STATIC catch_tests_runner.cpp include/catch.hpp)
target_link_libraries(hestia_catch_main PRIVATE athena_project_options)

add_executable(hestiaUnitTests catch_tests_runner.cpp src/maths/transform_tests.cpp src/maths/maths.cpp src/camera/camera_manager_tests.cpp)
target_link_libraries(hestiaUnitTests PRIVATE hestia_catch_main athena CONAN_PKG::glm CONAN_PKG::glfw glad)
target_link_libraries(hestiaUnitTests PRIVATE CONAN_PKG::catch2)
target_include_directories(hestiaUnitTests PRIVATE ../include)
target_compile_features(hestiaUnitTests INTERFACE cxx_std_17)

include(CTest)