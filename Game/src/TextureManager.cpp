//
// Created by Przemek on 15.09.2020.
//

#include "TextureManager.h"
#include <SDL2/SDL_image.h>

SDL_Texture *TextureManager::LoadTexture(const char *texture, SDL_Renderer *renderer) {
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* sdlTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return sdlTexture;
}
