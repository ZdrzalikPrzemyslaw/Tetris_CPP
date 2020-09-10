//
// Created by Przemek on 09.09.2020.
//

#include <iostream>
#include <memory>
#include "Figures/Figure.h"

void Figure::rotate() {
    int FIGURE_SIZE = this->shape[0].size();
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
    int FIGURE_SIZE = lhs.getShape().size();
    for (int i = 0; i < FIGURE_SIZE; i++) {
        for (int j = 0; j < FIGURE_SIZE; j++) {
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

Figure::Figure(Figure const &figure) {
    for (auto& i : figure.getShape()) {
        this->shape.emplace_back();
        for (auto& j : i) {
            this->shape.back().push_back(std::make_shared<Field>(j->isTaken()));
        }
    }
}

int Figure::getWidth() const {
    return this->shape.size();
}

int Figure::getHeight() const {
    return this->shape[0].size();
}

const std::pair<int, int> &Figure::getPos() const {
    return pos;
}

void Figure::setPos(int x_pos, int y_pos) {
    this->pos.first = x_pos;
    this->pos.second = y_pos;
}

int Figure::get_x_pos() {
    return this->pos.first;
}

int Figure::get_y_pos() {
    return this->pos.second;
}

void Figure::set_x_pos(int x_pos) {
    this->pos.first = x_pos;
}

void Figure::set_y_pos(int y_pos) {
    this->pos.second = y_pos;
}

void Figure::set_next_y_pos() {
    this->set_y_pos(this->get_y_pos() + 1);
}



