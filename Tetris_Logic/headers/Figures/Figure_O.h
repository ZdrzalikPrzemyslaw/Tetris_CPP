//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_FIGURE_O_H
#define TETRIS_FIGURE_O_H


#include "Figure.h"
#include "Shape_Generator.h"

/**
 * shape:
 *   x x
 *   x x
 */

class Figure_O : public Figure {
public:
    Figure_O();

    ~Figure_O();

private:

    std::vector<std::vector<std::shared_ptr<Field>>> baseShape =
            Shape_Generator::get_shape_from_vector(
                    {{1, 1},
                            {1, 1}}
            );
};


#endif //TETRIS_FIGURE_O_H
