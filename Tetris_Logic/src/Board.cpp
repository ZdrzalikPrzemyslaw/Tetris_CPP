//
// Created by Przemek on 09.09.2020.
//

#include <random>
#include <algorithm>
#include <chrono>
#include <iostream>
#include "Board.h"
#include "list"

void Board::step() {
    this->move_piece();
}

void Board::moveRight() {

}

void Board::moveLeft() {

}

void Board::rotate() {

}

void Board::speedUpFalling() {

}

Board::Board() {
    for (auto &i : this->fields) {
        for (auto &j : i) {
            j = std::make_shared<Field>(false);
        }
    }
    this->current_figure = std::make_shared<Figure>(get_random_figure());
    this->next_figure = std::make_shared<Figure>(get_random_figure());
    this->place_piece_on_board();
    // todo place figure on board
}

Board::~Board() {

}

void Board::set_next_piece() {

}

const int Board::getXDim() {
    return x_dim;
}

const int Board::getYDim() {
    return y_dim;
}

Figure Board::get_random_figure() {
    if (this->current_possible_figures_vector.empty()) {
        this->fill_current_possible_figures_vector();
    }
    Figure ret_fig(*this->current_possible_figures_vector[0]);
    this->current_possible_figures_vector.erase(this->current_possible_figures_vector.begin());
    return ret_fig;
}

//todo make it so the value that was last in vector (before re fill) doesnt get refilled
void Board::fill_current_possible_figures_vector() {
    for (auto &i : this->const_possible_figures_vector) {
        this->current_possible_figures_vector.push_back(i);
    }
    auto rng = std::default_random_engine{};
    rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(std::begin(this->current_possible_figures_vector), std::end(this->current_possible_figures_vector),
                 rng);
}

void Board::move_piece() {
    // todo test
    // todo make it only move the desired piece and no other blocks
    this->current_figure_pos.first++;
    int start_pos_x = this->current_figure_pos.second + this->current_figure->getWidth() - 1;
    int start_pos_y = this->current_figure_pos.first + this->current_figure->getHeight() - 1;
    for (int i = start_pos_x; i >= this->current_figure_pos.second; i--) {
        for (int j = start_pos_y; j >= this->current_figure_pos.first; j--) {
            std::cout << "j " << j << " i " << i << "\n";
            this->fields[j][i] = this->fields[j - 1][i];
        }
    }
}

void Board::place_piece_on_board() {
    // FixMe: Placeholder to see if it works, implement properly
    // todo: check if field is taken and game over
    int xbeg = 5;
    int ybeg = 0;
    this->current_figure_pos = std::pair(ybeg, xbeg);
    for (int i = 0; i < this->current_figure->getWidth(); i++) {
        for (int j = 0; j < this->current_figure->getHeight(); j++) {
            this->fields[this->current_figure_pos.first + i][this->current_figure_pos.second + j] = this->current_figure->getShape()[i][j];
        }
    }
}


std::string Board::to_string() {
    std::string return_string;
    for (auto &i : this->fields) {
        for (auto &j : i) {
            return_string += (*j).toString();
            return_string += " ";
        }
        return_string += "\n";
    }
    return return_string;
}


