//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include "SDL2/SDL.h"
#undef main
#include "iostream"

#include "memory"

class Game {
public:
    Game();

    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    void update();

    void render();

    void clean();

    void handle_events();

    bool get_is_running();

private:
    bool is_running;
    SDL_Window *window;
    SDL_Renderer *renderer;
};


#endif //TETRIS_GAME_H
