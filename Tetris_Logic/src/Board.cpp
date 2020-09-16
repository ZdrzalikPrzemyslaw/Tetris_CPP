//
// Created by Przemek on 09.09.2020.
//

#include <random>
#include <algorithm>
#include <chrono>
#include <iostream>
#include "Board.h"

// todo add game over
//  add tests for the class, 13.09.2020 refactor untested
//  najgorsza klasa w całej grze, łatwo się pogubić, nie wiem jak poprawić

void Board::step() {
    this->move_down();
}

void Board::moveRight() {
    this->move_figure_to(this->current_figure->get_x_pos() + 1, this->current_figure->get_y_pos());
}

void Board::moveLeft() {
    this->move_figure_to(this->current_figure->get_x_pos() - 1, this->current_figure->get_y_pos());
}

bool Board::move_down() {
    if (!this->move_figure_to(this->current_figure->get_x_pos(), this->current_figure->get_y_pos() + 1)) {
        this->set_current_figure_to_next_figure_and_get_new_next_figure();
        remove_full_rows();
        return false;
    }
    return true;
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

Board::Board() {
    for (auto &i : this->fields) {
        for (auto &j : i) {
            j = std::make_shared<Field>(false);
        }
    }
    this->set_current_figure_to_next_figure_and_get_new_next_figure();
    this->init_figure_on_board();
    // todo place figure on board
}

Board::~Board() = default;

void Board::set_next_figure() {
    this->next_figure = std::make_shared<Figure>(get_random_figure());
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

void Board::init_figure_on_board() {
    // todo: If the starting position for the figure is taken game over
    this->init_figure_pos();
    this->place_figure();
}

void Board::init_figure_pos() {
    // todo constant out the starting pos
    this->current_figure->setPos(4, 1 - this->current_figure->getHeight());
    bool isTaken = false;
    for (int i = 0; i < this->current_figure->getWidth(); i++) {
        for (int j = this->current_figure->getHeight() - 1; j < this->current_figure->getHeight(); j++) {
            if (this->current_figure->getShape()[j][i]->isTaken()) {
                isTaken = true;
            }
        }
    }
    if (!isTaken) {
        this->current_figure->set_next_y_pos();
    }
}


bool Board::place_figure() {
    if (!this->check_if_figure_can_be_placed())
        return false;
    // place figure in new position
    for (int i = 0; i < this->current_figure->getWidth(); i++) {
        for (int j = 0; j < this->current_figure->getHeight(); j++) {
            if (this->current_figure->getShape()[j][i]->isTaken()) {
                // only place in bounds, could also catch excpetion invalid access and ignore result
                if (j + this->current_figure->get_y_pos() >= 0) {
                    this->fields[this->current_figure->get_x_pos() + i][this->current_figure->get_y_pos() +
                                                                        j]->setIsTaken(true);
                }
            }
        }
    }
    return true;
}

void Board::remove_figure() {
    for (int i = 0; i < this->current_figure->getWidth(); i++) {
        for (int j = 0; j < this->current_figure->getHeight(); j++) {
            if (this->current_figure->getShape()[j][i]->isTaken())
                if (j + this->current_figure->get_y_pos() >= 0) {
                    this->fields[this->current_figure->get_x_pos() + i][this->current_figure->get_y_pos() +
                                                                        j]->setIsTaken(false);
                }
        }
    }
}

void Board::set_current_figure_to_next_figure_and_get_new_next_figure() {
    if (this->next_figure == nullptr)
        set_next_figure();
    this->current_figure = next_figure;
    this->set_next_figure();
    this->init_figure_on_board();
}

bool Board::check_if_figure_can_be_placed() {
    for (int i = 0; i < this->current_figure->getWidth(); i++) {
        for (int j = 0; j < this->current_figure->getHeight(); j++) {
            if (this->current_figure->getShape()[j][i]->isTaken()) {
                // check if we are in bounds x-axis
                if (this->current_figure->get_x_pos() + i < 0 ||
                    this->current_figure->get_x_pos() + i > Board::x_dim - 1)
                    return false;
                    // only check inside the bounds of board
                else if (j + this->current_figure->get_y_pos() >= 0) {
                    // check if we moved too far (figure pos is at the bottom), if yes return false so this->move_down() can do the work
                    if (j + this->current_figure->get_y_pos() >= y_dim) {
                        return false;
                    }
                    // if the position we want to move our figure to is taken return false
                    if (this->fields[this->current_figure->get_x_pos() + i][this->current_figure->get_y_pos() +
                                                                            j]->isTaken()) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

/// moving a piece consists of freeing the fields it currently occupies, changing its position and placing it back to the board
/// if the figure cant be moved to the target location for whatever reason it's moved back to its original position
bool Board::move_figure_to(int x_pos, int y_pos) {
    this->remove_figure();
    int xpos_before = this->current_figure->get_x_pos();
    int ypos_before = this->current_figure->get_y_pos();
    this->current_figure->set_x_pos(x_pos);
    this->current_figure->set_y_pos(y_pos);
    bool did_work = this->place_figure();
    if (!did_work) {
        this->current_figure->set_x_pos(xpos_before);
        this->current_figure->set_y_pos(ypos_before);
        this->place_figure();
    }
    return did_work;
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

// todo test
void Board::drop_figure_to_bottom() {
    while (this->move_down());
}

std::ostream &operator<<(std::ostream &osm, Board board) {
    osm << board.to_string();
    return osm;
}

// todo make safe
std::shared_ptr<Field> Board::get(int xpos, int ypos) {
    return this->fields[xpos][ypos];
}

// todo test
void Board::remove_full_rows() {
    for (int i = y_dim - 1; i >= 0; i--) {
        bool is_full = true;
        for (auto &field : this->fields) {
            if(!field[i]->isTaken()) {
                is_full = false;
            }
        }
        if (is_full) {
            for (int j = i; j > 0; j--) {
                for (auto & field : this->fields) {
                    field[j] = field[j - 1];
                }
            }
        }

    }
}

