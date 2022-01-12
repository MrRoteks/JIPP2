cmake_minimum_required(VERSION 3.20)
project(lab11)

set(CMAKE_CXX_STANDARD 17)

add_executable(pointerTest ../lab11/main.cpp include/pointer.h src/pointer.cpp)

include_directories(lab11/include/)
include_directories(lab11/src/)

add_library(pointerLib ./include/pointer.h ./src/pointer.cpp)
