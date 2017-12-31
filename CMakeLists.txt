cmake_minimum_required(VERSION 3.8)

project(fuzzy-inference-system)
set (fuzzy-inference-system_VERSION_MAJOR 1)
set (fuzzy-inference-system_VERSION_MINOR 0)


set(CMAKE_CXX_STANDARD 11)

file (GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.h)
add_executable(fuzzy-inference-system ${SOURCE_FILES} src/fuzzy/inference/InferenceSystem.cpp src/fuzzy/inference/InferenceSystem.h src/fuzzy/inference/Clause.cpp src/fuzzy/inference/Clause.h src/fuzzy/inference/FuzzyInput.cpp src/fuzzy/inference/FuzzyInput.h src/fuzzy/inference/Rule.cpp src/fuzzy/inference/Rule.h src/fuzzy/domain/RangeDomain.cpp src/fuzzy/domain/RangeDomain.h src/fuzzy/domain/CompositeDomain.cpp src/fuzzy/domain/CompositeDomain.h src/fuzzy/Defuzzifier.cpp src/fuzzy/Defuzzifier.h src/fuzzy/domain/Domain.cpp src/fuzzy/FuzzySet.cpp src/fuzzy/FuzzySet.h src/fuzzy/parser/Parser.h src/fuzzy/parser/VariableParser.cpp src/fuzzy/parser/VariableParser.h src/fuzzy/parser/Helper.h src/fuzzy/parser/Helper.cpp src/fuzzy/parser/RulesParser.cpp src/fuzzy/parser/RulesParser.h)
