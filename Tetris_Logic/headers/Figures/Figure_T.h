//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_FIGURE_T_H
#define TETRIS_FIGURE_T_H


#include "Figure.h"
#include "Shape_Generator.h"

class Figure_T : public Figure {
public:
    Figure_T();

    ~Figure_T();

private:
    std::vector<std::vector<std::shared_ptr<Field>>> baseShape =
            Shape_Generator::get_shape_from_array(
                    {{ {0, 0, 0, 0},
                             {0, 0, 0, 0},
                             {0, 0, 1, 0},
                             {0, 1, 1, 1}}}
            );
};

#endif //TETRIS_FIGURE_T_H
