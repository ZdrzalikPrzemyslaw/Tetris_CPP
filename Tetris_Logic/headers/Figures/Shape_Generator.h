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
    get_shape_from_vector(const std::vector<std::vector<int>>& vector);
};


#endif //TETRIS_SHAPE_GENERATOR_H
