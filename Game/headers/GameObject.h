//
// Created by Przemek on 15.09.2020.
//

#ifndef TETRIS_GAMEOBJECT_H
#define TETRIS_GAMEOBJECT_H


#include <SDL2/SDL_render.h>

class GameObject {
public:
    GameObject(const char *texturesheet, SDL_Renderer *renderer, SDL_Rect srcRect, int xpos, int ypos);

    GameObject();

    ~GameObject();

    void Update();

    void Render();

    void setVisibility(bool visible);

private:

    int xpos;
    int ypos;
    bool isvisible;

    SDL_Texture *objTexture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
    SDL_Renderer *sdlRenderer;

};


#endif //TETRIS_GAMEOBJECT_H
