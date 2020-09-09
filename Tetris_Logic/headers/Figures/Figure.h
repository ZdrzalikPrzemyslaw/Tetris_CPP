//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_FIGURE_H
#define TETRIS_FIGURE_H

#include <memory>
#include "vector"
#include "Field.h"

class Figure {
public:
    void rotate();
    static const int FIGURE_SIZE = 4;
protected:
    std::vector<std::vector<std::shared_ptr<Field>>> shape;
public:
    std::string toString();
};


#endif //TETRIS_FIGURE_H
