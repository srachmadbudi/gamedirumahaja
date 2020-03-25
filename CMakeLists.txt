cmake_minimum_required(VERSION 3.6)
project(paaquiz2)

set(CMAKE_CXX_STANDARD 14)
include_directories(include/)
add_executable(paaquiz2 main.cpp include/Graph.h Graph.cpp Trap_game.cpp include/Trap_game.h include/Player.h include/Level.h)