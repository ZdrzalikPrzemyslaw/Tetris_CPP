//
// Created by Przemek on 15.09.2020.
//

#ifndef TETRIS_TEXTUREMANAGER_H
#define TETRIS_TEXTUREMANAGER_H

#include <SDL2/SDL.h>
#include <string>

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char *texture, SDL_Renderer* renderer);
};


#endif //TETRIS_TEXTUREMANAGER_H
