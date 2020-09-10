project(GameLibrary)

set(SOURCE_FILES
        headers/Game.h src/Game.cpp)

add_library(Game_lib ${SOURCE_FILES} )

target_link_libraries(Game_lib Tetris_Logic_Lib)

target_include_directories(Game_lib PUBLIC include)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/headers
)

enable_testing()