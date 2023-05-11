cmake_minimum_required(VERSION 3.25)
project(Shooting_Game)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(${External/include})
include_directories("Header Files")
include_directories("Source Files")

add_executable(Shooting_Game
        "Shooting-Game-2023/Game.h"
        "Shooting-Game-2023/Game.cpp"
        "Shooting-Game-2023/main.cpp"
        "Shooting-Game-2023/Player.h"
        "Shooting-Game-2023/Player.cpp"
        )
