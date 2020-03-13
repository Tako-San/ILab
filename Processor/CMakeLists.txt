cmake_minimum_required(VERSION 3.15)
project(Processor)

set(CMAKE_CXX_STANDARD 14)

add_executable(Processor Assembler/main.cpp
                         Assembler/assembler.cpp
                         Assembler/assembler.h
                         StackClass/stack.cpp
                         StackClass/stack.h
                         Str_funcs/str_funcs.cpp
                         Str_funcs/str_funcs.h)