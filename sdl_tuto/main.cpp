//
//  main.cpp
//  SDL Tutorial
//
//  Created by Gabriel T Marques on 01/05/19.
//  Copyright © 2019 Gabriel T Marques. All rights reserved.
//

#include "Game.hpp"

Game *game = nullptr;

int main(int argsc, const char *argv[])
{
    int fpsLimit = 60; // fps
    int timeForFrame = 1000; // ms
    const int frameDelay = timeForFrame / fpsLimit;
    
    Uint32 frameStart;
    int frameTime;
    
    game = new Game();
    
    game->init("C++ - GameEngine [in development]", 1280, 720, false);
    
    while(game->isRunning()) {
        frameStart = SDL_GetTicks();
        
        game->handleEvents();
        game->update();
        game->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    
    game->clean();
    return EXIT_SUCCESS;
}
