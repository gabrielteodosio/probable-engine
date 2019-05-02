//
//  Game.cpp
//  SDL Tutorial
//
//  Created by Gabriel T Marques on 01/05/19.
//  Copyright © 2019 Gabriel T Marques. All rights reserved.
//

#include "Game.hpp"

struct Dimensions {
    int WIDTH = 50;
    int HEIGHT = 37;
};

Dimensions playerDimensions;

GameObject *player;
GameObject *enemy;

SDL_Renderer *Game::renderer = nullptr;

Game::Game() {
    
}

Game::~Game() {
    
}

void Game::init(const char *title, int width, int height, bool fullscreen) {
    int flags = 0;
    if ( fullscreen ) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if ( SDL_Init(SDL_INIT_EVERYTHING) == 0 ) {
        std::cout << "Subsystems initialized" << std::endl;
        
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        if ( window ) {
            std::cout << "Window created" << std::endl;
        }
        
        renderer = SDL_CreateRenderer(window, -1, flags);
        if ( renderer ) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
            std::cout << "Renderer created" << std::endl;
        }
        
        running = true;
    } else {
        running = false;
    }
    
    const char* playerSpritePath = "assets/adventurer-idle-2-00.png";
    const char* enemySpritePath = "assets/adventurer-bow-00.png";
    
    player = new GameObject(playerSpritePath, 0, 0);
    enemy = new GameObject(enemySpritePath, 57, 0);
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;

        default:
            break;
    }
}

void Game::update() {
    player->update();
    enemy->update();
}

void Game::render() {
    SDL_RenderClear(renderer);
    
    // this is where we would add stuff to render
    player->render();
    enemy->render();
    
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "game cleaned" << std::endl;
}
