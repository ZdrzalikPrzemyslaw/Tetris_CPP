//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H


#include <Figures/Figure.h>
#include <string_view>
#include "map"

class Board {
public:
    static const int x_dim = 10;
    static const int y_dim = 20;
    void step();
    void moveRight();
    void moveLeft();
    void rotate();
    void speedUpFalling();
    Board();
    ~Board();

private:
    std::map<char, bool> figure_bool_map = {
            {'I', true},
            {'J', true},
            {'L', true},
            {'O', true},
            {'S', true},
            {'T', true},
            {'Z', true},
    };
    std::shared_ptr<Figure> current_figure;
    std::shared_ptr<Figure> next_figure;
    std::array<std::array<Field, y_dim>, x_dim> fields;
    void set_next_piece();
};


#endif //TETRIS_BOARD_H
