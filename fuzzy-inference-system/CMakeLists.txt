cmake_minimum_required(VERSION 3.8)

project(fuzzy-inference-system)
set(fuzzy-inference-system_VERSION_MAJOR 1)
set(fuzzy-inference-system_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ./domain
        ./domain/CompositeDomain.cpp
        ./domain/CompositeDomain.h
        ./domain/Domain.cpp
        ./domain/Domain.h
        ./domain/DomainElement.cpp
        ./domain/DomainElement.h
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

# add_executable(fuzzy-inference-system main.cpp)
add_library(fuzzy-inference-system ${SOURCE_FILES})
