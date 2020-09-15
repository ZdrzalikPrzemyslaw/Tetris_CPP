//
// Created by Przemek on 15.09.2020.
//

#ifndef TETRIS_FRAMELIMITER_H
#define TETRIS_FRAMELIMITER_H


#include "SDL2/SDL_types.h"

class FrameLimiter {
private:
    int FPS;
    int frameDelay;
    Uint32 frameStart;
public:
    FrameLimiter(int FPS);
    void wait();
};


#endif //TETRIS_FRAMELIMITER_H
