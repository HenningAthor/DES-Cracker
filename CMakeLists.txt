cmake_minimum_required(VERSION 3.15)
project(DES_Cracker)

set(CMAKE_CXX_STANDARD 14)

add_executable(DES_Cracker main.cpp DESCracker.cpp DESCracker.hpp)

find_package(OpenMP)
if (OpenMP_CXX_FOUND)
    target_link_libraries(DES_Cracker PUBLIC OpenMP::OpenMP_CXX)
endif ()