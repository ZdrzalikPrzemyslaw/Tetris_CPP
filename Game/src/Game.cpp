//
// Created by Przemek on 09.09.2020.
//

#include "Game.h"

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
    this->renderer = SDL_CreateRenderer(this->window, -1, 0);
    SDL_SetRenderDrawColor(this->renderer, 0, 255, 0, 255);
    SDL_RenderClear(this->renderer);
    SDL_RenderPresent(this->renderer);
    SDL_Delay(3000);
}

Game::Game() {

}

Game::~Game() {

}

void Game::update() {

}

void Game::render() {

}

void Game::clean() {

}

void Game::handle_events() {

}

bool Game::get_is_running() {
    return false;
}
