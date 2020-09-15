//
// Created by Przemek on 15.09.2020.
//

#include "TextureManager.h"
#include <SDL2/SDL_image.h>

SDL_Texture *TextureManager::loadTexture(const char *texture, SDL_Renderer *renderer) {
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* sdlTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    printf("IMG_Load: %s\n", IMG_GetError());
    SDL_FreeSurface(tempSurface);
    return sdlTexture;
}
