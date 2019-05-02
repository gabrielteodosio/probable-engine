//
//  GameObject.hpp
//  sdl_tutorial
//
//  Created by Gabriel T Marques on 01/05/19.
//  Copyright © 2019 Gabriel T Marques. All rights reserved.
//

#pragma once
#include "Game.hpp"

class GameObject {
public:
    GameObject(const char *textureSheet, SDL_Renderer *renderer, int xpos, int ypos);
    ~GameObject();
    
    void update();
    void render();

private:
    int xpos, ypos;
    
    SDL_Texture *objTexture;
    SDL_Rect srcR, destR;
    SDL_Renderer *renderer;

};
