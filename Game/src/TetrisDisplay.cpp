//
// Created by Przemek on 16.09.2020.
//

#include "TetrisDisplay.h"

TetrisDisplay::TetrisDisplay(SDL_Renderer *renderer, Board* board) {
    this->board = board;
    SDL_Rect sdlRect;
    sdlRect.h = 32;
    sdlRect.w = 32;
    sdlRect.x = 0;
    sdlRect.y = 0;
    this->sdlRenderer = renderer;
    for (int i = 0; i < y_dim; i++) {
        for (int j = 0; j < x_dim; j++) {
            this->pGameObject[j][i] = GameObject("assets/field.png", this->sdlRenderer, sdlRect, j * 32, i * 32);
        }
    }
    this->update();
}

void TetrisDisplay::update() {
    for (int i = 0; i < y_dim; i++) {
        for (int j = 0; j < x_dim; j++) {
            this->pGameObject[j][i].setVisibility(this->board->get(j, i)->isTaken());
        }
    }
}

void TetrisDisplay::render() {
    for(auto& i : this->pGameObject) {
        for (auto& j : i) {
            j.Render();
        }
    }
}

TetrisDisplay::TetrisDisplay() = default;

TetrisDisplay::~TetrisDisplay() = default;
