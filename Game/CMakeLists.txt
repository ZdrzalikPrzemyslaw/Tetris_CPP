project(GameLibrary)

set(SOURCE_FILES
        headers/Game.h src/Game.cpp src/TextureManager.cpp headers/TextureManager.h src/FrameLimiter.cpp headers/FrameLimiter.h)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_library(Game_lib ${SOURCE_FILES} )
target_link_libraries(Game_lib Tetris_Logic_Lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
target_include_directories(Game_lib PUBLIC headers)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/headers
)

enable_testing()