cmake_minimum_required(VERSION 3.8)

project(FIS)
set(FIS_VERSION_MAJOR 1)
set(FIS_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ./domain
        ./domain/Domain.h
        ./domain/RangeDomain.cpp
        ./domain/RangeDomain.h
        ./fuzzyset/FuzzySet.cpp
        ./fuzzyset/FuzzySet.h
        ./fuzzyset/MembershipFunction.cpp
        ./fuzzyset/MembershipFunction.h
        ./fuzzyset/Operators.cpp
        ./fuzzyset/Operators.h
        ./inference/Clause.cpp
        ./inference/Clause.h
        ./inference/Defuzzifier.cpp
        ./inference/Defuzzifier.h
        ./inference/FuzzyInput.cpp
        ./inference/FuzzyInput.h
        ./inference/InferenceSystem.cpp
        ./inference/InferenceSystem.h
        ./inference/Rule.cpp
        ./inference/Rule.h
        ./language_variable/LanguageTerm.cpp
        ./language_variable/LanguageTerm.h
        ./language_variable/LanguageVariable.cpp
        ./language_variable/LanguageVariable.h
        ./parser/Helper.cpp
        ./parser/Helper.h
        ./parser/Parser.h
        ./parser/RulesParser.cpp
        ./parser/RulesParser.h
        ./parser/VariableParser.cpp
        ./parser/VariableParser.h
        )

# add_executable(FIS ${SOURCE_FILES} main.cpp)
add_library(FIS ${SOURCE_FILES})

