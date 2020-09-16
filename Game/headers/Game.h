//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include <Board.h>
#include "SDL2/SDL.h"
#include "TetrisDisplay.h"
#undef main

// todo : https://www.youtube.com/playlist?list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx - tutoriale
class Game {
public:
    Game();

    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    void update();

    void render();

    void clean();

    void handle_events();

    bool get_is_running() const;

private:
    Board *board;
    int counter = 0;
    bool is_running;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *background;
    TetrisDisplay tetrisDisplay;
    Uint32 lastTetrisDownMove;
    bool KEYS[322];
    void handleInput(const Uint8 *keyboard_state_array);
};


#endif //TETRIS_GAME_H
