cmake_minimum_required(VERSION 3.8)

project(anfis)
set (anfis_VERSION_MAJOR 1)
set (anfis_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SRC
     "**/*.h"
     "**/*.cpp")

add_executable(anfis main.cpp ${SRC})