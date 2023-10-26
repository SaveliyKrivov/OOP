cmake_minimum_required(VERSION 3.26)
project(OOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP main.cpp
        Player.h
        Player.cpp
        Controller.cpp
        Controller.h
        Field/Cell.cpp
        Field/Cell.h
        Field/Field.h
        Field/Field.cpp
        Events/Event.h
        Events/PlayerEvent.h
        Events/Heal.h
        Events/Heal.cpp
        Field/FieldBuilder.h
        Field/FieldBuilder.cpp
        Events/PlayerEvent.cpp
        Events/Coin.h
        Events/Coin.cpp
        Events/Enemy.cpp
        Events/Enemy.h
        Events/Teleport.cpp
        Events/Teleport.h
        Events/FieldEvent.cpp
        Events/FieldEvent.h
)
