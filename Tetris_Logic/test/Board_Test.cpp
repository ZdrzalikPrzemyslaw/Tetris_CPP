//
// Created by Przemek on 09.09.2020.
//

#include <boost/test/unit_test.hpp>
#include <Board.h>


// https://strategywiki.org/wiki/Tetris/Rotation_systems

BOOST_AUTO_TEST_SUITE(Board_Test)

    BOOST_AUTO_TEST_CASE(Board_TMP_Test) {
        Board board;
        std::cout << board.to_string() << "\n";
        board.step();
        std::cout << board.to_string();
    }

BOOST_AUTO_TEST_SUITE_END()