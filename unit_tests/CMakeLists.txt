cmake_minimum_required(VERSION 3.5)


if(CONAN_CATCH2_ROOT_DEBUG)
    include(${CONAN_CATCH2_ROOT_DEBUG}/lib/cmake/Catch2/Catch.cmake)
else()
    include(${CONAN_CATCH2_ROOT}/lib/cmake/Catch2/Catch.cmake)
endif()

add_library(hestia_catch_main STATIC catch_tests_runner.cpp)
target_link_libraries(hestia_catch_main
        PRIVATE
        hestia_project_options
        CONAN_PKG::catch2)

add_executable(hestia_unit_tests
        src/maths/transform_tests.cpp
        src/maths/maths.cpp
        src/camera/camera_manager_tests.cpp)

target_link_libraries(hestia_unit_tests
        PRIVATE
        hestia_catch_main
        athena
        CONAN_PKG::glm
        CONAN_PKG::glfw
        CONAN_PKG::catch2
        glad)
target_include_directories(hestia_unit_tests
        PRIVATE
        ../include)

catch_discover_tests(
        hestia_unit_tests
        TEST_PREFIX
        "unittests."
        REPORTER
        xml
        OUTPUT_DIR
        .
        OUTPUT_PREFIX
        "unittests."
        OUTPUT_SUFFIX
        .xml)