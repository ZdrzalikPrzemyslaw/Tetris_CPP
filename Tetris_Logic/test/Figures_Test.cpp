//
// Created by Przemek on 09.09.2020.
//

#include <boost/test/unit_test.hpp>
#include <Figures/Figure_I.h>
#include "Figures/Custom_Figure.h"

BOOST_AUTO_TEST_SUITE(Figures_Test)
    std::vector<std::vector<Field *>> custom_original = {
            {new Field(true),  new Field(false), new Field(true),  new Field(false)},
            {new Field(false), new Field(false), new Field(false), new Field(false)},
            {new Field(false), new Field(false), new Field(false), new Field(false)},
            {new Field(false), new Field(false), new Field(false), new Field(false)}
    };

    std::vector<std::vector<Field *>> custom_rotated = {
            {new Field(false), new Field(false), new Field(false), new Field(true)},
            {new Field(false), new Field(false), new Field(false), new Field(false)},
            {new Field(false), new Field(false), new Field(false), new Field(true)},
            {new Field(false), new Field(false), new Field(false), new Field(false)}
    };

    BOOST_AUTO_TEST_CASE(Test_Rotate_Custom_Figure) {
        Figure customFigure = Custom_Figure(custom_original);
        Figure customFigureShouldBeRotated = Custom_Figure(custom_rotated);
        customFigure.rotate();
        BOOST_REQUIRE_EQUAL(customFigure, customFigureShouldBeRotated);
    }

    std::vector<std::vector<Field *>> rotated_figure_I = {
            {new Field(false), new Field(true), new Field(false), new Field(false)},
            {new Field(false), new Field(true), new Field(false), new Field(false)},
            {new Field(false), new Field(true), new Field(false), new Field(false)},
            {new Field(false), new Field(true), new Field(false), new Field(false)}
    };

    BOOST_AUTO_TEST_CASE(Test_Rotate_Figure_I) {
        Figure_I figure_I = Figure_I();
        Figure figure_I_should_be_rotated = Custom_Figure(rotated_figure_I);
        figure_I.rotate();
        BOOST_REQUIRE_EQUAL(figure_I, figure_I_should_be_rotated);
    }

BOOST_AUTO_TEST_SUITE_END()