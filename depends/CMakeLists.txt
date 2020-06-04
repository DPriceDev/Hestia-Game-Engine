cmake_minimum_required(VERSION 3.5)

add_library(stblib INTERFACE)
target_link_directories(stblib INTERFACE stb)
target_include_directories(stblib INTERFACE ./stb)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(athena)
add_subdirectory(glad)
add_subdirectory(glfw)
add_subdirectory(glm)