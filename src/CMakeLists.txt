cmake_minimum_required(VERSION 3.15)

file(GLOB_RECURSE all_SRCS
        "*.cpp"
        "*.c")

add_library(hestia STATIC ${all_SRCS} ../include)
target_link_libraries(hestia PRIVATE
        hestia_project_options
        project_warnings
        OpenGL::GL
        athena
        CONAN_PKG::glm
        CONAN_PKG::glfw
        CONAN_PKG::stb
        glad)
target_include_directories(hestia PUBLIC ../include)

add_custom_command(
        TARGET hestia POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_CURRENT_SOURCE_DIR}/../assets
                ${CMAKE_BINARY_DIR}/src/assets)