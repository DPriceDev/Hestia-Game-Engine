cmake_minimum_required(VERSION 3.5)

# Build and Link Library
add_library(glad STATIC glad/glad.c glad/glad.h)
target_include_directories(glad PUBLIC .)
target_compile_features(glad PUBLIC cxx_std_17)