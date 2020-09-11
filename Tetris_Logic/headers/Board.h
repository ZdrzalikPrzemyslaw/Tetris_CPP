//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H

#include "Figures/Figure.h"
#include <string_view>
#include "Figures/Figure_I.h"
#include "Figures/Figure_J.h"
#include "Figures/Figure_L.h"
#include "Figures/Figure_O.h"
#include "Figures/Figure_S.h"
#include "Figures/Figure_T.h"
#include "Figures/Figure_Z.h"
#include "map"

class Board {
public:
    void step();
    void moveRight();
    void moveLeft();
    void rotate();
    Board();
    ~Board();
    static int getXDim();
    static int getYDim();
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
    std::shared_ptr<Figure> next_figure;
    std::shared_ptr<Field> fields [x_dim][y_dim];
    void set_next_figure();
    Figure get_random_figure();
    void fill_current_possible_figures_vector();
    void move_piece();
    void init_figure_on_board();
    void init_figure_pos();
    bool place_figure();
    void remove_figure();
    void set_current_figure_to_next_figure_and_get_new_next_figure();
};


#endif //TETRIS_BOARD_H
