cmake_minimum_required(VERSION 3.20)
project(Projekt1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projekt1 matrixApp/main.cpp matrixLib/include/matrixLib.h matrixLib/src/matrixLib.cpp)

include_directories(matrixLib/include/)
include_directories(matrixLib/src/)
