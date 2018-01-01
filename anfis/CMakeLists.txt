cmake_minimum_required(VERSION 3.8)

project(fuzzy-inference-system)
set (fuzzy-inference-system_VERSION_MAJOR 1)
set (fuzzy-inference-system_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SRC
     "**/*.h"
     "**/*.cpp")

add_executable(fuzzy-inference-system main.cpp ${SRC})