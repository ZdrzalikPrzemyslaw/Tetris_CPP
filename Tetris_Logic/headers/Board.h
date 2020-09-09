//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H

#include <Figures/Figure.h>
#include <string_view>
#include <Figures/Figure_I.h>
#include <Figures/Figure_J.h>
#include <Figures/Figure_L.h>
#include <Figures/Figure_O.h>
#include <Figures/Figure_S.h>
#include <Figures/Figure_T.h>
#include <Figures/Figure_Z.h>
#include "map"

class Board {
public:
    void step();
    void moveRight();
    void moveLeft();
    void rotate();
    void speedUpFalling();
    Board();
    ~Board();
    static const int getXDim();
    static const int getYDim();
    std::string to_string();

private:
    static const int x_dim = 10;
    static const int y_dim = 20;
    const std::vector<std::shared_ptr<Figure>> const_possible_figures_vector = {
        std::make_shared<Figure_I>(),
        std::make_shared<Figure_J>(),
        std::make_shared<Figure_L>(),
        std::make_shared<Figure_O>(),
        std::make_shared<Figure_S>(),
        std::make_shared<Figure_T>(),
        std::make_shared<Figure_Z>(),
    };
    std::vector<std::shared_ptr<Figure>> current_possible_figures_vector;
    std::shared_ptr<Figure> current_figure;
    std::pair<int, int> current_figure_pos;
    std::shared_ptr<Figure> next_figure;
    std::array<std::array<std::shared_ptr<Field>, x_dim>, y_dim> fields;
    void set_next_piece();
    Figure get_random_figure();
    void fill_current_possible_figures_vector();
    void move_piece();
    void place_piece_on_board();
};


#endif //TETRIS_BOARD_H
