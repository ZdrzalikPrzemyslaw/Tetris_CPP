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
    this->remove_figure();
    this->current_figure->set_x_pos(this->current_figure->get_x_pos() + 1);
    bool did_work = this->place_figure();
    if (!did_work) {
        this->current_figure->set_x_pos(this->current_figure->get_x_pos() - 1);
        this->place_figure();
    }
}

void Board::moveLeft() {
    this->remove_figure();
    this->current_figure->set_x_pos(this->current_figure->get_x_pos() - 1);
    bool did_work = this->place_figure();
    if (!did_work) {
        this->current_figure->set_x_pos(this->current_figure->get_x_pos() + 1);
        this->place_figure();
    }
}

void Board::rotate() {
    this->remove_figure();
    this->current_figure->rotate();
    bool did_work = this->place_figure();
    if (!did_work) {
        // todo add counter rotation method
        this->current_figure->rotate();
        this->current_figure->rotate();
        this->current_figure->rotate();
        this->place_figure();
    }
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
    this->remove_figure();
    this->current_figure->set_next_y_pos();
    bool did_work = this->place_figure();
    // todo check if piece is at the bottom
    if (!did_work) {
        // todo end control of piece and get next piece
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
bool Board::place_figure() {
    // if the position we want to move our figure to is taken return false
    for (int i = 0; i < this->current_figure->getWidth(); i++) {
        for (int j = 0; j < this->current_figure->getHeight(); j++) {
            if (this->current_figure->getShape()[i][j]->isTaken()) {
                if (this->fields[this->current_figure->get_x_pos() + i][this->current_figure->get_y_pos() +
                                                                        j]->isTaken()) {
                    return false;
                }
            }
        }
    }
    // place figure in new position
    for (int i = 0; i < this->current_figure->getWidth(); i++) {
        for (int j = 0; j < this->current_figure->getHeight(); j++) {
            if (this->current_figure->getShape()[i][j]->isTaken())
                this->fields[this->current_figure->get_x_pos() + i][this->current_figure->get_y_pos() + j]->setIsTaken(true);
        }
    }
    return true;
}

// todo make work from bottom to top
void Board::remove_figure() {
    for (int i = 0; i < this->current_figure->getWidth(); i++) {
        for (int j = 0; j < this->current_figure->getHeight(); j++) {
            if (this->current_figure->getShape()[i][j]->isTaken())
                this->fields[this->current_figure->getPos().first + i][this->current_figure->getPos().second +
                                                                       j]->setIsTaken(false);
        }
    }
}


