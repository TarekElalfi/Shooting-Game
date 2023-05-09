cmake_minimum_required(VERSION 3.25)
project(Shooting_Game)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories("Header Files")
include_directories("Source Files")

add_executable(Shooting_Game
        "Header Files/Game.h"
        "Source Files/Game.cpp"
        "Source Files/main.cpp")
