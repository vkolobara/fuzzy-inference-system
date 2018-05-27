cmake_minimum_required(VERSION 3.8)

project(fuzzy)
set (fuzzy_VERSION_MAJOR 1)
set (fuzzy_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(ANFIS)
add_subdirectory(FIS)
