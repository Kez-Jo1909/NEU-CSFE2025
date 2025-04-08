cmake_minimum_required(VERSION 3.22)
project(test1)

set(CMAKE_CXX_STANDARD 20)

add_executable(test1 main.cpp
    ./src/sparse_matrix.cpp
    ./include/sparse_matrix.hpp
)
