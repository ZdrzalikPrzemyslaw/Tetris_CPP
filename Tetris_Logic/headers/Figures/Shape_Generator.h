//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_SHAPE_GENERATOR_H
#define TETRIS_SHAPE_GENERATOR_H


#include <Field.h>
#include "memory"
#include "Figure.h"

class Shape_Generator {
public:
    static std::vector<std::vector<std::shared_ptr<Field>>>
    get_shape_from_array(std::array<std::array<int, Figure::FIGURE_SIZE>, Figure::FIGURE_SIZE> array);

};


#endif //TETRIS_SHAPE_GENERATOR_H
