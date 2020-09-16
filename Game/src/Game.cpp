//
// Created by Przemek on 09.09.2020.
//

#include "Game.h"
#include "TextureManager.h"
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
    this->board = new Board();
    this->tetrisDisplay = TetrisDisplay(this->renderer, this->board);
    this->lastTetrisDownMove = SDL_GetTicks();
}

Game::Game() {

}

Game::~Game() {
    delete board;
}

void Game::update() {
    int frameTime = SDL_GetTicks() - this->lastTetrisDownMove;
    if (frameTime > this->fall_delay){
        this->board->step();
        this->lastTetrisDownMove = SDL_GetTicks();
    }
    tetrisDisplay.update();
}

void Game::render() {
    SDL_RenderClear(this->renderer);
    tetrisDisplay.render();
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
    const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                this->is_running = false;
                break;
            // todo not sure if works
            case SDL_KEYDOWN:
                this->handleInput(keyboard_state_array);
                break;
            case SDL_KEYUP:
                this->handleInputKeyUp(keyboard_state_array);
                break;
            default:
                break;
        }
    }
}

bool Game::get_is_running() const {
    return this->is_running;
}

void Game::handleInput(const Uint8 *keyboard_state_array) {
    if (keyboard_state_array[SDL_SCANCODE_LEFT]) {
        this->board->moveLeft();
    }
    if (keyboard_state_array[SDL_SCANCODE_RIGHT]) {
        this->board->moveRight();
    }
    if (keyboard_state_array[SDL_SCANCODE_DOWN]) {
        this->fall_delay = 50;
    }
    if (keyboard_state_array[SDL_SCANCODE_UP]) {
        this->board->rotate();
    }
    if (keyboard_state_array[SDL_SCANCODE_SPACE]) {
        this->board->drop_figure_to_bottom();
    }
}

void Game::handleInputKeyUp(const Uint8 *keyboard_state_array) {
    if (!keyboard_state_array[SDL_SCANCODE_DOWN]) {
        this->fall_delay = 1000;
    }
}
