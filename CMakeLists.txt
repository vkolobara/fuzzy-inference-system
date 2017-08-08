cmake_minimum_required(VERSION 3.8)
project(diplomski)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp fuzzy/MembershipFunctions.h fuzzy/MembershipFunctions.cpp fuzzy/LanguageVariable.cpp fuzzy/LanguageVariable.h fuzzy/Operators.h fuzzy/Operators.cpp fuzzy/domain/Domain.h)
add_executable(diplomski ${SOURCE_FILES})
