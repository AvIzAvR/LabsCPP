cmake_minimum_required(VERSION 3.26)
project(Lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab1 main.cpp
        Lab1.h
        Lab1lib.cpp
        Class.h
        ../Lab6/lab6.cpp
        ../Lab6/lab6.h
        ../Lab8/Lab8.cpp
        ../Lab8/Lab8.h)
