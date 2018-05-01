cmake_minimum_required(VERSION 3.8)

project(FIS)
set(FIS_VERSION_MAJOR 1)
set(FIS_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        norm/Norm.cpp
        norm/Norm.h
        language_variable/LanguageTerm.cpp
        language_variable/LanguageTerm.h
        ./language_variable/LanguageVariable.cpp
        ./language_variable/LanguageVariable.h
        language_variable/LanguageTerm.cpp
        rule/Antecedent.cpp
        rule/Antecedent.h
        rule/Rule.cpp
        rule/Rule.h
        rule/InferenceSystem.cpp
        rule/InferenceSystem.h
        rule/Clause.cpp
        rule/Clause.h
        parser/VariableParser.cpp
        parser/VariableParser.h
        parser/Parser.h
        parser/Helper.h parser/Helper.cpp rule/Consequent.cpp rule/Consequent.h rule/KnowledgeBase.cpp rule/KnowledgeBase.h)

# add_executable(FIS ${SOURCE_FILES} main.cpp)
add_library(FIS ${SOURCE_FILES})

