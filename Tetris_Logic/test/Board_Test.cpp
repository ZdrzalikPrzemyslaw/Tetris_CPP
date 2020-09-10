//
// Created by Przemek on 09.09.2020.
//

#include <boost/test/unit_test.hpp>
#include <Board.h>


// https://strategywiki.org/wiki/Tetris/Rotation_systems

BOOST_AUTO_TEST_SUITE(Board_Test)

    BOOST_AUTO_TEST_CASE(Board_TMP_Test) {
    // todo for now just to see if it works visually
        Board board;
        std::cout << board.to_string() << "\n";
        board.step();
        board.step();
        std::cout << board.to_string() << "\n";
        for(int i = 0; i < 30; i++) {
            board.moveRight();
        }
        std::cout << board.to_string() << "\n";
    }

BOOST_AUTO_TEST_SUITE_END()