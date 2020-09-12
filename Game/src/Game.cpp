//
// Created by Przemek on 09.09.2020.
//

#include "Game.h"
#include <iostream>

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;

    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        // todo remove or make good
        std::cout << "Subsystems initialized " << std::endl;

        this->window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            // todo remove or make good
            std::cout << "Window created" << std::endl;
        }

        this->renderer = SDL_CreateRenderer(this->window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
            // todo remove or make good
            std::cout << "Renderer created" << std::endl;
        }

        this->is_running = true;
    } else {
        this->is_running = false;
    }
//    SDL_SetRenderDrawColor(this->renderer, 0, 255, 0, 255);
//    SDL_RenderClear(this->renderer);
//    SDL_RenderPresent(this->renderer);
//    SDL_Delay(3000);
}

Game::Game() {

}

Game::~Game() {
//    delete this->renderer;
//    delete this->window;
}

void Game::update() {
    std::cout << counter << std::endl;
    counter++;
}

void Game::render() {
    SDL_RenderClear(this->renderer);
    // todo add stuff to render
    SDL_RenderPresent(this->renderer);
}

void Game::clean() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}

void Game::handle_events() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            this->is_running = false;
            break;
        default:
            break;
    }

}

bool Game::get_is_running() const {
    return this->is_running;
}
