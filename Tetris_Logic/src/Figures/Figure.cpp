//
// Created by Przemek on 09.09.2020.
//

#include <iostream>
#include <memory>
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

const std::vector<std::vector<std::shared_ptr<Field>>> &Figure::getShape() const {
    return shape;
}

std::ostream &operator<<(std::ostream &osm, Figure figure) {
    osm << figure.toString();
    return osm;
}

bool operator==(const Figure &lhs, const Figure &rhs) {
    for (int i = 0; i < Figure::FIGURE_SIZE; i++) {
        for (int j = 0; j < Figure::FIGURE_SIZE; j++) {
            if (*lhs.getShape()[i][j] != *rhs.getShape()[i][j]) {
                return false;
            }
        }
    }
    return true;
}

Figure::Figure() {
    for (int i = 0; i < FIGURE_SIZE; i++) {
        this->shape.emplace_back();
        for (int j = 0; j < FIGURE_SIZE; j++) {
            this->shape.back().push_back(std::make_shared<Field>(false));
        }
    }
}

Figure::~Figure() {

}


