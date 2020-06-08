cmake_minimum_required(VERSION 3.15)

# set the project name
project(Hestia-Game-Engine LANGUAGES CXX C VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# may fix the issue of amigious templates?
#-frelaxed-template-template-args

include(cmake/StandardProjectSettings.cmake)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    option(ENABLE_BUILD_WITH_TIME_TRACE "Enable -ftime-trace to generate time tracing .json files on clang" OFF)
    if (ENABLE_BUILD_WITH_TIME_TRACE)
        add_compile_definitions(project_options INTERFACE -ftime-trace)
    endif()
endif()

add_library(project_warnings INTERFACE)

# enable cache system
#include(cmake/Cache.cmake)

# enable doxygen
include(cmake/Doxygen.cmake)
enable_doxygen()

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# sanitizer options if supported by compiler
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

# allow for static analysis options
include(cmake/StaticAnalyzers.cmake)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)
option(ENABLE_TESTING "Enable Test Builds" ON)

option(ENABLE_PCH "Enable Precompiled Headers" OFF)
if (ENABLE_PCH)
    target_precompile_headers(project_options INTERFACE <vector> <utility> <algorithm> <array>)
endif()

# Library
find_package(OpenGL REQUIRED)

add_subdirectory(depends)
add_subdirectory(src)

add_library(hestia::hestia ALIAS hestia)

# Enable catch2 Testing
if(ENABLE_TESTING)
    enable_testing()
    message("Building Hestia Unit Tests.")
    add_subdirectory(unit_tests PRIVATE)
endif()

#todo: Add fuzz testing~