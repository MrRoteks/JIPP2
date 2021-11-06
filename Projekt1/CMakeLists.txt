cmake_minimum_required(VERSION 3.20)
project(Projekt1)

set(CMAKE_CXX_STANDARD 17)

add_executable(matrixApp matrixApp/main.cpp matrixLib/include/matrixLib.h matrixLib/src/matrixLib.cpp ../Lab4/Klasy_i_Obiekty/Przyklad/klasyIobiekty.cpp)

include_directories(matrixLib/include/)
include_directories(matrixLib/src/)

add_library(matrixLib matrixLib/include/matrixLib.h matrixLib/src/matrixLib.cpp)
