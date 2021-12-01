cmake_minimum_required(VERSION 3.16)

project(zadanieNotatnik)
include_directories(include)

add_executable(notes src/main.cpp src/notatnik.cpp)