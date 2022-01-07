cmake_minimum_required(VERSION 3.20)
project(Lab9)

set(CMAKE_CXX_STANDARD 20)

add_executable(vectorExample Stop.cpp vExample.cpp Line.cpp Line.h Line.cpp Stop.cpp Line.h Stop.h)
