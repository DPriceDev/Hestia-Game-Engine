cmake_minimum_required(VERSION 3.5)

include_directories(include)
include_directories(../include)
include_directories(../src)

add_executable(hestiaCatchTests catch_tests_runner.cpp include/catch.hpp include/maths/transform_tests.cpp include/maths/maths.cpp)

include(CTest)