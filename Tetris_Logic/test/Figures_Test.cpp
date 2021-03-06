//
// Created by Przemek on 09.09.2020.
//

#include <boost/test/unit_test.hpp>
#include <Figures/Figure_I.h>
#include <Figures/Figure_J.h>
#include <Figures/Figure_L.h>
#include <Figures/Figure_O.h>
#include <Figures/Figure_S.h>
#include <Figures/Figure_T.h>
#include <Figures/Figure_Z.h>
#include "Figures/Custom_Figure.h"

// https://strategywiki.org/wiki/Tetris/Rotation_systems

BOOST_AUTO_TEST_SUITE(Figures_Test)

    auto custom_original = Shape_Generator::get_shape_from_vector(
             {{1, 0, 1, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}}
    );


    auto custom_rotated = Shape_Generator::get_shape_from_vector(
             {{0, 0, 0, 1},
                     {0, 0, 0, 0},
                     {0, 0, 0, 1},
                     {0, 0, 0, 0}}
    );

    BOOST_AUTO_TEST_CASE(Test_Rotate_Custom_Figure) {
        Figure customFigure = Custom_Figure(custom_original);
        Figure customFigureShouldBeRotated = Custom_Figure(custom_rotated);
        customFigure.rotate();
        BOOST_REQUIRE_EQUAL(customFigure, customFigureShouldBeRotated);
    }

    auto rotated_figure_I = Shape_Generator::get_shape_from_vector(
             {{0, 1, 0, 0},
                     {0, 1, 0, 0},
                     {0, 1, 0, 0},
                     {0, 1, 0, 0}});

    BOOST_AUTO_TEST_CASE(Test_Rotate_Figure_I) {
        Figure *figure_I = new Figure_I();
        Figure figure_I_should_be_rotated = Custom_Figure(rotated_figure_I);
        figure_I->rotate();
        BOOST_REQUIRE_EQUAL(*figure_I, figure_I_should_be_rotated);
    }

    auto rotated_figure_J = Shape_Generator::get_shape_from_vector(
             {{1, 1, 0},
                     {1, 0, 0},
                     {1, 0, 0},}
    );

    BOOST_AUTO_TEST_CASE(Test_Rotate_Figure_J) {
        Figure *figure_J = new Figure_J();
        Figure figure_I_should_be_rotated = Custom_Figure(rotated_figure_J);
        figure_J->rotate();
        BOOST_REQUIRE_EQUAL(*figure_J, figure_I_should_be_rotated);
    }

    auto rotated_figure_L = Shape_Generator::get_shape_from_vector(
             {{1, 0, 0},
                     {1, 0, 0},
                     {1, 1, 0}}
    );

    BOOST_AUTO_TEST_CASE(Test_Rotate_Figure_L) {
        Figure *figure_L = new Figure_L();
        Figure figure_L_should_be_rotated = Custom_Figure(rotated_figure_L);
        figure_L->rotate();
        BOOST_REQUIRE_EQUAL(*figure_L, figure_L_should_be_rotated);
    }

    auto rotated_figure_O = Shape_Generator::get_shape_from_vector(
             {{1, 1},
              {1, 1}}
    );

    BOOST_AUTO_TEST_CASE(Test_Rotate_Figure_O) {
        Figure *figure_O = new Figure_O();
        Figure figure_O_should_be_rotated = Custom_Figure(rotated_figure_O);
        figure_O->rotate();
        BOOST_REQUIRE_EQUAL(*figure_O, figure_O_should_be_rotated);
    }

    auto rotated_figure_S = Shape_Generator::get_shape_from_vector(
             {{1, 0, 0},
                     {1, 1, 0},
                     {0, 1, 0,}}
    );

    BOOST_AUTO_TEST_CASE(Test_Rotate_Figure_S) {
        Figure *figure_S = new Figure_S();
        Figure figure_S_should_be_rotated = Custom_Figure(rotated_figure_S);
        figure_S->rotate();
        BOOST_REQUIRE_EQUAL(*figure_S, figure_S_should_be_rotated);
    }

    auto rotated_figure_T = Shape_Generator::get_shape_from_vector(
            {{0, 1, 0},
                    {0, 1, 1},
                    {0, 1, 0,}}
    );

    BOOST_AUTO_TEST_CASE(Test_Rotate_Figure_T) {
        Figure *figure_T = new Figure_T();
        Figure figure_T_should_be_rotated = Custom_Figure(rotated_figure_T);
        figure_T->rotate();
        BOOST_REQUIRE_EQUAL(*figure_T, figure_T_should_be_rotated);
    }

    auto rotated_figure_Z = Shape_Generator::get_shape_from_vector(
            {{0, 1, 0},
             {1, 1, 0},
             {1, 0, 0,}}
    );

    BOOST_AUTO_TEST_CASE(Test_Rotate_Figure_Z) {
        Figure *figure_Z = new Figure_Z();
        Figure figure_Z_should_be_rotated = Custom_Figure(rotated_figure_Z);
        figure_Z->rotate();
        BOOST_REQUIRE_EQUAL(*figure_Z, figure_Z_should_be_rotated);
    }

BOOST_AUTO_TEST_SUITE_END()