cmake_minimum_required(VERSION 3.5)

add_library(stblib INTERFACE)
target_link_directories(stblib INTERFACE stb)
target_include_directories(stblib INTERFACE ./stb)

add_subdirectory(athena)
add_subdirectory(glad)