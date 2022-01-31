cmake_minimum_required(VERSION 3.20)
project(Projekt_koncowy)

set(CMAKE_CXX_STANDARD 17)

add_executable(csvEditorApp csvEditorApp/main.cpp csvEditorLib/include/csvEditorLib.h csvEditorLib/src/csvEditorLib.cpp )

include_directories(csvEditorLib/include/)
include_directories(csvEditorLib/src/)

add_library(csvEditorLib csvEditorLib/include/csvEditorLib.h csvEditorLib/src/csvEditorLib.cpp)
