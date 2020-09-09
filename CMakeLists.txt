cmake_minimum_required(VERSION 3.17)
project(Tetris)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Game)
add_subdirectory(Tetris_Logic)

add_executable(Tetris main.cpp)