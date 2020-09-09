//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_FIGURE_I_H
#define TETRIS_FIGURE_I_H


#include "Figures/Figure.h"
#include "Shape_Generator.h"

class Figure_I : public Figure {
public:
    Figure_I();

    ~Figure_I();

private:
    std::vector<std::vector<std::shared_ptr<Field>>> baseShape =
            Shape_Generator::get_shape_from_vector(
                     {{0, 0, 0, 0},
                             {0, 0, 0, 0},
                             {1, 1, 1, 1},
                             {0, 0, 0, 0}}
            );
};


#endif //TETRIS_FIGURE_I_H
