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
    this->init_figure_on_board();
    // todo place figure on board
}

Board::~Board() {

}

void Board::set_next_piece() {

}

int Board::getXDim() {
    return x_dim;
}

int Board::getYDim() {
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
    this->current_figure->setPos(this->current_figure->get_x_pos(), this->current_figure->get_y_pos() + 1);
    for (int i = this->current_figure->getWidth() - 1; i >= 0; i--) {
        for (int j = this->current_figure->getHeight() - 1; j >= 0; j--) {
            int y_pos = j + current_figure->get_x_pos();
            int x_pos = i + current_figure->get_y_pos();
            std::cout << "xpos " << x_pos << " ypos " << y_pos << "\n";
            if (this->current_figure->getShape()[j][i]->isTaken()) {
                this->fields[y_pos][x_pos] = this->fields[y_pos - 1][x_pos];
                this->fields[y_pos - 1][x_pos]->setIsTaken(false);
            }
        }
    }
}





void Board::init_figure_on_board() {
    // FixMe: Placeholder to see if it works, implement properly
    // todo: check if field is taken and game over
    this->init_figure_pos();
    this->place_figure();
}


std::string Board::to_string() {
    std::string return_string;
    for (int i = 0; i < y_dim; i++) {
        for (auto &field : this->fields) {
            return_string += field[i]->toString();
            return_string += " ";
        }
        return_string += "\n";
    }
    return return_string;
}

void Board::init_figure_pos() {
    this->current_figure->setPos(4, 0);
}

// todo make work from bottom to top (so that when figure is first placed into the board only part of it can be placed)
void Board::place_figure() {
    for (int i = 0; i < this->current_figure->getWidth(); i++) {
        for (int j = 0; j < this->current_figure->getHeight(); j++) {
            if (this->current_figure->getShape()[i][j]->isTaken())
                this->fields[this->current_figure->getPos().first + i][this->current_figure->getPos().second + j]->setIsTaken(true);
        }
    }
}

// todo make work from bottom to top
void Board::remove_figure() {
    for (int i = 0; i < this->current_figure->getWidth(); i++) {
        for (int j = 0; j < this->current_figure->getHeight(); j++) {
            if (this->current_figure->getShape()[i][j]->isTaken())
                this->fields[this->current_figure->getPos().first + i][this->current_figure->getPos().second + j]->setIsTaken(false);
        }
    }
}


