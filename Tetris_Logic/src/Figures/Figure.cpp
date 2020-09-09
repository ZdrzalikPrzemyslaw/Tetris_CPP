//
// Created by Przemek on 09.09.2020.
//

#include <iostream>
#include "Figures/Figure.h"

void Figure::rotate() {
    for (int x = 0; x < FIGURE_SIZE / 2; x++) {
        for (int y = x; y < FIGURE_SIZE - x - 1; y++) {

            auto tmp_field = this->shape[x][y];

            this->shape[x][y] = this->shape[FIGURE_SIZE - 1 - y][x];

            this->shape[FIGURE_SIZE - 1 - y][x] = this->shape[FIGURE_SIZE - 1 - x][FIGURE_SIZE - 1 - y];

            this->shape[FIGURE_SIZE - 1 - x][FIGURE_SIZE - 1 - y] = this->shape[y][FIGURE_SIZE - 1 - x];

            this->shape[y][FIGURE_SIZE - 1 - x] = tmp_field;
        }
    }
}


std::string Figure::toString() {
    std::string full_string;
    for (auto &i : this->shape) {
        for (auto &j : i) {
            full_string += (*j).toString();
            full_string += " ";
        }
        full_string += "\n";
    }
    return full_string;
}

