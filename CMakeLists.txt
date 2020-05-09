cmake_minimum_required(VERSION 3.2)

# set the project name
project(hestia-game-engine VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(depends/glfw)
add_subdirectory(depends/glm)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/src/*/*/*/*/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*/*/*/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/**/*/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*/*/*.c"
        "${PROJECT_SOURCE_DIR}/src/*/*.c"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        )

set (
      INCLUDE_DIRS
      include
      include/glfw
      include/glfw/include
      include/glfw/include/GLFW
      depends/glm
      depends
      depends/stb
      depends/stb/
      include/glad
    )

include_directories(${INCLUDE_DIRS})
add_library(hestia STATIC ${all_SRCS})
# add_executable(libhge.a ${all_SRCS})
target_link_libraries(hestia OpenGL::GL)
target_link_libraries(hestia glfw)
target_link_libraries(hestia glm)
target_include_directories(hestia PUBLIC ${INCLUDE_DIRS})