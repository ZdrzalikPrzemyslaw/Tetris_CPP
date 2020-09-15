//
// Created by Przemek on 15.09.2020.
//

#include <SDL_timer.h>
#include <cstdio>
#include "FrameLimiter.h"

FrameLimiter::FrameLimiter(int FPS) {
    this->FPS = FPS;
    this->frameDelay = 1000 / FPS;
    this->frameStart = SDL_GetTicks();
}

void FrameLimiter::wait() {
    int frameTime = SDL_GetTicks() - frameStart;
    if (frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime);
    }
    this->frameStart = SDL_GetTicks();
}
