cmake_minimum_required(VERSION 3.8)

project(fuzzy-inference-system)
set (fuzzy-inference-system_VERSION_MAJOR 1)
set (fuzzy-inference-system_VERSION_MINOR 0)


set(CMAKE_CXX_STANDARD 11)

file (GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.h)
add_executable(fuzzy-inference-system ${SOURCE_FILES} src/fuzzy/inference/InferenceSystem.cpp src/fuzzy/inference/InferenceSystem.h src/fuzzy/inference/Clause.cpp src/fuzzy/inference/Clause.h src/fuzzy/inference/FuzzyInput.cpp src/fuzzy/inference/FuzzyInput.h)
