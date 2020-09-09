//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_FIGURE_H
#define TETRIS_FIGURE_H

#include "vector"
#include "Field.h"

class Figure {
public:
    void rotate();
private:
    static const int FIGURE_SIZE = 4;
protected:
    Field shape[FIGURE_SIZE][FIGURE_SIZE];
};


#endif //TETRIS_FIGURE_H
