//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_CUSTOM_FIGURE_H
#define TETRIS_CUSTOM_FIGURE_H

#include "Figures/Figure.h"

class Custom_Figure : public Figure {
public:
    Custom_Figure(const std::vector<std::vector<std::shared_ptr<Field>>> &shape);
};


#endif //TETRIS_CUSTOM_FIGURE_H
