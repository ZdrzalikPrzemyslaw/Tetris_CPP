//
// Created by Przemek on 15.09.2020.
//

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *texturesheet, SDL_Renderer *renderer, SDL_Rect srcRect, int xpos, int ypos) {
    this->objTexture = TextureManager::loadTexture(texturesheet, renderer);
    this->sdlRenderer = renderer;
    this->srcRect = srcRect;
    this->xpos = xpos;
    this->ypos = ypos;
    this->destRect.h = srcRect.h;
    this->destRect.w = srcRect.w;
    this->destRect.x = xpos;
    this->destRect.y = ypos;
    this->isvisible = false;
}

GameObject::~GameObject() = default;

void GameObject::Update() {

}

void GameObject::setVisibility(bool visible) {
    this->isvisible = visible;
}

void GameObject::Render() {
    if (this->isvisible)
        SDL_RenderCopy(this->sdlRenderer, this->objTexture, &this->srcRect, &this->destRect);
}

GameObject::GameObject() = default;
