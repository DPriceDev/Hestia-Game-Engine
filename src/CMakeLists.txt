cmake_minimum_required(VERSION 3.15)

file(GLOB_RECURSE all_SRCS
        "*.cpp"
        "*.c")

add_library(hestia OBJECT ${all_SRCS} ../include)
target_link_libraries(hestia PRIVATE stblib OpenGL::GL project_options)
target_link_libraries(hestia PUBLIC glm::glm athena glfw glad)
target_include_directories(hestia PUBLIC ../include)
target_compile_features(hestia PUBLIC cxx_std_17)