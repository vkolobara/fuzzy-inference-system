cmake_minimum_required(VERSION 3.8)

project(anfis)
set(anfis_VERSION_MAJOR 1)
set(anfis_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SRC
        "**/*.h"
        "**/*.cpp"
        "../fuzzy-inference-system/fuzzyset/MembershipFunction.h"
        "../fuzzy-inference-system/fuzzyset/MembershipFunction.cpp"
        )

add_executable(anfis main.cpp ${SRC} layer/OutputLayer.cpp layer/OutputLayer.h layer/Layer.h membership/AnfisMembershipFunction.h membership/GaussMembershipFunction.cpp membership/GaussMembershipFunction.h membership/SigmoidMembershipFunction.cpp membership/SigmoidMembershipFunction.h layer/AntecedentLayer.cpp layer/AntecedentLayer.h tnorm/TNorm.cpp tnorm/TNorm.h layer/NormalizingLayer.cpp layer/NormalizingLayer.h layer/ConsequentLayer.cpp layer/ConsequentLayer.h layer/ANFIS.cpp layer/ANFIS.h loss/Loss.cpp loss/Loss.h algorithm/Backpropagation.cpp algorithm/Backpropagation.h)