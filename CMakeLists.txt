cmake_minimum_required(VERSION 3.16)
project(Tetris)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Game)
add_subdirectory(Tetris_Logic)

add_executable(Tetris main.cpp)

target_link_libraries(Tetris
        Tetris_Logic_Lib
        Game_lib
)

add_custom_command(TARGET Tetris POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:Tetris>/assets)

enable_testing()