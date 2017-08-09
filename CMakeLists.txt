cmake_minimum_required(VERSION 3.8)
project(diplomski)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/fuzzy/MembershipFunctions.h src/fuzzy/MembershipFunctions.cpp src/fuzzy/LanguageVariable.cpp src/fuzzy/LanguageVariable.h src/fuzzy/Operators.h src/fuzzy/Operators.cpp src/fuzzy/domain/Domain.h)
add_executable(diplomski ${SOURCE_FILES})
