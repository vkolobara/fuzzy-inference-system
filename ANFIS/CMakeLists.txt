cmake_minimum_required(VERSION 3.8)

project(ANFIS)
set(ANFIS_VERSION_MAJOR 1)
set(ANFIS_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ./algorithm/Backpropagation.cpp
        ./algorithm/Backpropagation.h
        ./layer/ANFIS.cpp
        ./layer/ANFIS.h
        ./layer/AntecedentLayer.cpp
        ./layer/AntecedentLayer.h
        ./layer/ConsequentLayer.cpp
        ./layer/ConsequentLayer.h
        ./layer/Layer.h
        ./layer/NormalizingLayer.cpp
        ./layer/NormalizingLayer.h
        ./layer/OutputLayer.cpp
        ./layer/OutputLayer.h
        ./loss/Loss.cpp
        ./loss/Loss.h
        ./membership/AnfisMembershipFunction.h
        ./membership/GaussMembershipFunction.cpp
        ./membership/GaussMembershipFunction.h
        ./membership/SigmoidMembershipFunction.cpp
        ./membership/SigmoidMembershipFunction.h
        ./tnorm/TNorm.cpp
        ./tnorm/TNorm.h
        )

add_library(ANFIS ${SOURCE_FILES})