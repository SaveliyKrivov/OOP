cmake_minimum_required(VERSION 3.26)
project(OOP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(OOP main.cpp
        Player/Player.h
        Player/Player.cpp
        Control/Controller.cpp
        Control/Controller.h
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
        GameExecution/GameManager.cpp
        GameExecution/GameManager.h
        Field/ShowField.cpp
        Field/ShowField.h
        GameExecution/ReadFile.cpp
        GameExecution/ReadFile.h
        GameExecution/ReadConsoleCmnds.cpp
        GameExecution/ReadConsoleCmnds.h
        Observer/Observer.cpp
        Observer/Observer.h
        Observer/Monitor.h
        Observer/MonitorStats.cpp
        Observer/MonitorStats.h
        Observer/MonitorCoordinates.cpp
        Observer/MonitorCoordinates.h
        Observer/MonitorGameState.cpp
        Observer/MonitorGameState.h
        Logging/Message.h
        Logging/Message.cpp
        Logging/PlayerWon.cpp
        Logging/PlayerWon.h
        Logging/MessageHandler.cpp
        Logging/MessageHandler.h
        Logging/PlayerLost.cpp
        Logging/PlayerLost.h
        Logging/GameStarted.cpp
        Logging/GameStarted.h
        Logging/ValidCommandPressed.cpp
        Logging/ValidCommandPressed.h
        Logging/InvalidCommandPressed.cpp
        Logging/InvalidCommandPressed.h
)
