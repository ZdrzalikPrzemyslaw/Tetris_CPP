//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_FIGURE_J_H
#define TETRIS_FIGURE_J_H

#include "Figure.h"
#include "Shape_Generator.h"

/**
 * shape:
 * x
 * x x x
 */

class Figure_J : public Figure {
public:
    Figure_J();

    ~Figure_J();

private:
    std::vector<std::vector<std::shared_ptr<Field>>> baseShape =
            Shape_Generator::get_shape_from_vector(
                     {{0, 0, 0},
                             {1, 0, 0},
                             {1, 1, 1}}
            );
};


#endif //TETRIS_FIGURE_J_H
