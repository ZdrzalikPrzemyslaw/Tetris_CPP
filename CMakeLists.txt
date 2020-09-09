cmake_minimum_required(VERSION 3.17)
project(Tetris)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tetris main.cpp Tetris_Logic/src/Board.cpp Tetris_Logic/headers/Board.h Game/src/Game.cpp Game/headers/Game.h)