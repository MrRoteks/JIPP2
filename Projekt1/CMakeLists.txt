cmake_minimum_required(VERSION 3.20)
project(Projekt1)

set(CMAKE_CXX_STANDARD 17)

add_executable(betterMatrixApp betterMatrixApp/main.cpp betterMatrixLib/include/matrixLib.h betterMatrixLib/src/matrixLib.cpp )

include_directories(betterMatrixLib/include/)
include_directories(betterMatrixLib/src/)

add_library(betterMatrixLib betterMatrixLib/include/matrixLib.h betterMatrixLib/src/matrixLib.cpp)
