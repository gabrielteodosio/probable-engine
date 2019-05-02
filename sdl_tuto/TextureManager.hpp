//
//  TextureManager.hpp
//  sdl_tutorial
//
//  Created by Gabriel T Marques on 01/05/19.
//  Copyright © 2019 Gabriel T Marques. All rights reserved.
//

#pragma once
#include "Game.hpp"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char *fileName, SDL_Renderer *ren);
};
