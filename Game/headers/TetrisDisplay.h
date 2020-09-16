//
// Created by Przemek on 16.09.2020.
//

#ifndef TETRIS_TETRISDISPLAY_H
#define TETRIS_TETRISDISPLAY_H

#include "SDL2/SDL_render.h"
#include <Board.h>
#include "GameObject.h"

class TetrisDisplay {
public:
    TetrisDisplay(SDL_Renderer *renderer, Board *board);
    TetrisDisplay();
    ~TetrisDisplay();
    void update();
    void render();

private:
    static const int x_dim = 10;
    static const int y_dim = 20;
    Board *board{};
    GameObject pGameObject[x_dim][y_dim];
    SDL_Renderer *sdlRenderer{};
};


#endif //TETRIS_TETRISDISPLAY_H
