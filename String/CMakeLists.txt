cmake_minimum_required(VERSION 3.15)
project(String)

set(CMAKE_CXX_STANDARD 14)

add_executable(String mystring.cpp
                      mystring.h
                      test.cpp)