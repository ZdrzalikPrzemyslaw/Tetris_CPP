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
#include "Static_Board_Constant.h"
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
    friend std::ostream& operator<<(std::ostream& osm, Board board);
    std::shared_ptr<Field> get(int x_pos, int y_pos);

    void drop_figure_to_bottom();

private:
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
    std::shared_ptr<Field> fields [Static_Board_Constant::Static_Board_Constant::x_dim][Static_Board_Constant::Static_Board_Constant::y_dim];
    void set_next_figure();
    Figure get_random_figure();
    void fill_current_possible_figures_vector();
    bool move_down();
    void init_figure_on_board();
    void init_figure_pos();
    bool place_figure();
    void remove_figure();
    void set_current_figure_to_next_figure_and_get_new_next_figure();
    bool check_if_figure_can_be_placed();
    bool move_figure_to(int x_pos, int y_pos);

    void remove_full_rows();
};


#endif //TETRIS_BOARD_H
