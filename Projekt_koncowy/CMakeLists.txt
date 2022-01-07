cmake_minimum_required(VERSION 3.20)
project(Projekt_koncowy)

set(CMAKE_CXX_STANDARD 17)

add_executable(statisticsMathChekerApp statisticsMathChekerApp/main.cpp statisticMathChekerLib/include/statisticMathChekerLib.h statisticMathChekerLib/src/statisticMathChekerLib.cpp ../Lab4/Klasy_i_Obiekty/Przyklad/klasyIobiekty.cpp)

include_directories(statisticMathChekerLib/include/)
include_directories(statisticMathChekerLib/src/)

add_library(statisticMathChekerLib statisticMathChekerLib/include/statisticMathChekerLib.h statisticMathChekerLib/src/statisticMathChekerLib.cpp ../Lab9/Przyklad/main.cpp)
