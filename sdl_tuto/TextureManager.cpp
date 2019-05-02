//
//  TextureManager.cpp
//  sdl_tutorial
//
//  Created by Gabriel T Marques on 01/05/19.
//  Copyright © 2019 Gabriel T Marques. All rights reserved.
//

#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char *texture, SDL_Renderer *ren){
    SDL_Surface *tempSurface = IMG_Load(texture);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
}
