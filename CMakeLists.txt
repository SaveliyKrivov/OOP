cmake_minimum_required(VERSION 3.26)
project(OOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP main.cpp
        Player.h
        Player.cpp
        Controller.cpp
        Controller.h
        Cell.cpp
        Cell.h
        Field.h
        Field.cpp
)
