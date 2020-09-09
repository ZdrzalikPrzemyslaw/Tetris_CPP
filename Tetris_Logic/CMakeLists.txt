project(TetrisLogicLib)

set(SOURCE_FILES
        headers/Board.h src/Board.cpp headers/Figures/Figure.h src/Field.cpp headers/Field.h src/Figures/Figure.cpp)

set(SOURCE_TEST_FILES
        test/master.cpp test/Example_Test.cpp)

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

add_library(Tetris_Logic_Lib ${SOURCE_FILES})

add_executable (Test_Tetris_Logic ${SOURCE_TEST_FILES})

target_include_directories(Tetris_Logic_Lib PUBLIC include)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/headers
        ${Boost_INCLUDE_DIRS}
)

target_link_libraries(
        Test_Tetris_Logic
        Tetris_Logic_Lib
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

IF(WIN32)
    target_link_libraries (Test_Tetris_Logic
            -lbcrypt
            )
ENDIF(WIN32)

add_test(Lib_Test_1 Test_Tetris_Logic
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()