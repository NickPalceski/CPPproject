cmake_minimum_required(VERSION 3.27)
project(CPPproject)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CPPproject
        main.cpp
        Player.cpp
        Player.h
        gameLoop.cpp)
