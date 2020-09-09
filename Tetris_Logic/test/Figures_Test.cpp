//
// Created by Przemek on 09.09.2020.
//

#include <boost/test/unit_test.hpp>
#include "Figures/Custom_Figure.h"

BOOST_AUTO_TEST_SUITE(Example_Test)
    BOOST_AUTO_TEST_CASE(Test_Rotate) {
        std::vector<std::vector<Field*>> vector;
        std::vector<Field*> figure_vector1 = {new Field(true), new Field(false), new Field(true), new Field(false)};
        std::vector<Field*> figure_vector2 = {new Field(false), new Field(false), new Field(false), new Field(false)};
        std::vector<Field*> figure_vector3 = {new Field(false), new Field(false), new Field(false), new Field(false)};
        std::vector<Field*> figure_vector4 = {new Field(false), new Field(false), new Field(false), new Field(false)};
        vector.push_back(figure_vector1);
        vector.push_back(figure_vector2);
        vector.push_back(figure_vector3);
        vector.push_back(figure_vector4);
        Figure customFigure = Custom_Figure(vector);
        customFigure.rotate();
    }
BOOST_AUTO_TEST_SUITE_END()