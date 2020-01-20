cmake_minimum_required(VERSION 3.15)
project(Processor)

set(CMAKE_CXX_STANDARD 14)

add_executable(Processor Stack/main.cpp Stack/interface.cpp Stack/interface.h Stack/stack.cpp Stack/stack.h)