//
// Created by Przemek on 09.09.2020.
//

#include <boost/test/unit_test.hpp>
#include "Figures/Custom_Figure.h"

BOOST_AUTO_TEST_SUITE(Example_Test)
    std::vector<std::vector<Field*>> vector_original = {
            {new Field(true), new Field(false), new Field(true), new Field(false)},
            {new Field(false), new Field(false), new Field(false), new Field(false)},
            {new Field(false), new Field(false), new Field(false), new Field(false)},
            {new Field(false), new Field(false), new Field(false), new Field(false)}
    };

    std::vector<std::vector<Field*>> vector_rotated = {
            {new Field(false), new Field(false), new Field(false), new Field(true)},
            {new Field(false), new Field(false), new Field(false), new Field(false)},
            {new Field(false), new Field(false), new Field(false), new Field(true)},
            {new Field(false), new Field(false), new Field(false), new Field(false)}
    };
    BOOST_AUTO_TEST_CASE(Test_Rotate) {
        Figure customFigure = Custom_Figure(vector_original);
        Figure customFigureShouldBeRotated = Custom_Figure(vector_rotated);
        customFigure.rotate();
        BOOST_REQUIRE_EQUAL(customFigure, customFigureShouldBeRotated);

    }
BOOST_AUTO_TEST_SUITE_END()