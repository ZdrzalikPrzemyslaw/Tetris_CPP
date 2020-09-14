project(TetrisLogicLib)

set(SOURCE_FILES
        headers/Board.h src/Board.cpp headers/Figures/Figure.h src/Field.cpp headers/Field.h src/Figures/Figure.cpp src/Figures/Custom_Figure.cpp headers/Figures/Custom_Figure.h src/Figures/Figure_I.cpp headers/Figures/Figure_I.h src/Figures/Figure_O.cpp headers/Figures/Figure_O.h src/Figures/Figure_T.cpp headers/Figures/Figure_T.h src/Figures/Figure_S.cpp headers/Figures/Figure_S.h src/Figures/Figure_Z.cpp headers/Figures/Figure_Z.h src/Figures/Figure_J.cpp headers/Figures/Figure_J.h src/Figures/Figure_L.cpp headers/Figures/Figure_L.h src/Figures/Shape_Generator.cpp headers/Figures/Shape_Generator.h headers/Game_Over_Exception.h)

set(SOURCE_TEST_FILES
        test/master.cpp test/Figures_Test.cpp test/Board_Test.cpp)

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

add_library(Tetris_Logic_Lib ${SOURCE_FILES})

add_executable (Logic_Test ${SOURCE_TEST_FILES})

target_include_directories(Tetris_Logic_Lib PUBLIC headers)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/headers
        ${Boost_INCLUDE_DIRS}
)

target_link_libraries(
        Logic_Test
        Tetris_Logic_Lib
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

IF(WIN32)
    target_link_libraries (Logic_Test
            -lbcrypt
            )
ENDIF(WIN32)

add_test(Lib_Test_1 Logic_Test
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()