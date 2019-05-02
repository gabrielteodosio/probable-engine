//
//  Game.hpp
//  SDL Tutorial
//
//  Created by Gabriel T Marques on 01/05/19.
//  Copyright © 2019 Gabriel T Marques. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "TextureManager.hpp"
#include "GameObject.hpp"

class Game {
public:
    Game(); // constructor
    ~Game(); // deconstructor
    
    void init(const char* title, int width, int height, bool fullscreen);
    
    void handleEvents();
    void update();
    void render();
    void clean();
    bool isRunning() { return running; }
    
    static SDL_Renderer *renderer;
    
    int getCnt() { return cnt; }
    void setCnt(int cnt) { this->cnt = cnt; }

private:
    int fpsLimit;
    int cnt;
    bool running;
    
    SDL_Window *window;
};

#endif /* Game_hpp */
