//
//  GameObject.cpp
//  sdl_tutorial
//
//  Created by Gabriel T Marques on 01/05/19.
//  Copyright © 2019 Gabriel T Marques. All rights reserved.
//

#include "GameObject.hpp"

GameObject::GameObject(const char *textureSheet, SDL_Renderer *renderer, int xpos, int ypos) {
    this->renderer = renderer;
    objTexture = TextureManager::LoadTexture(textureSheet, this->renderer);
    
    this->xpos = xpos;
    this->ypos = ypos;
}

void GameObject::update() {
    this->xpos++;
    this->ypos++;
    
    this->srcR.h = 37;
    this->srcR.w = 50;
    this->srcR.x = 0;
    this->srcR.y = 0;
    
    this->destR.x = xpos;
    this->destR.y = ypos;
    this->destR.w = this->srcR.w * 2;
    this->destR.h = this->srcR.h * 2;
}

void GameObject::render() {
    SDL_RenderCopy(this->renderer, this->objTexture, &this->srcR, &this->destR);
}
