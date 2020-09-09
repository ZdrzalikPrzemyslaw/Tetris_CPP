//
// Created by Przemek on 09.09.2020.
//

#include <boost/test/unit_test.hpp>
#include "Figures/Custom_Figure.h"

BOOST_AUTO_TEST_SUITE(Example_Test)
    BOOST_AUTO_TEST_CASE(Test_Rotate) {
        std::vector<std::vector<Field*>> vector = {
                {new Field(true), new Field(false), new Field(true), new Field(false)},
                {new Field(false), new Field(false), new Field(false), new Field(false)},
                {new Field(false), new Field(false), new Field(false), new Field(false)},
                {new Field(false), new Field(false), new Field(false), new Field(false)}
        };
        Figure customFigure = Custom_Figure(vector);
        customFigure.rotate();
        std::cout << customFigure;
    }
BOOST_AUTO_TEST_SUITE_END()