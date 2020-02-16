cmake_minimum_required(VERSION 3.15)
project(DES_Cracker)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-std=c++11 -Ofast -march=native -g -ffast-math -Wall")

add_executable(DES_Cracker main.cpp DESCracker.cpp DESCracker.hpp)

find_package(OpenMP)
if (OpenMP_CXX_FOUND)
    target_link_libraries(DES_Cracker PUBLIC OpenMP::OpenMP_CXX)
endif ()