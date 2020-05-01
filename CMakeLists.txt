cmake_minimum_required(VERSION 3.2)

# set the project name
project(hestia-game-engine VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(depends/glfw)
include_directories(depends/glfw/include)

find_package(OpenGL REQUIRED)


file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/src/*/*/*/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/**/*/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*/*/*.c"
        "${PROJECT_SOURCE_DIR}/src/*/*.c"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set (
      INCLUDE_DIRS
      include
      include/glfw
      include/glfw/include
      include/glfw/include/GLFW
      depends/glm
      depends
      include/glad
    )

include_directories(${INCLUDE_DIRS})
add_executable(engine.app ${all_SRCS})
target_link_libraries(engine.app OpenGL::GL)
target_link_libraries(engine.app glfw)