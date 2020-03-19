cmake_minimum_required(VERSION 3.15)
project(MAP)

set(CMAKE_CXX_STANDARD 14)

add_executable(MAP
        map.h
        map.cpp
        map_operators.h
        node.h
        node.cpp
        tree.h
        tree.cpp
        test.cpp)