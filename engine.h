#ifndef ENGINE_H
#define ENGINE_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "game.h"
#include "graphics.h"

enum GameState { 
    BEGIN,
    RED_PLAYER,
    BLUE_PLAYER,
    RED_PLAYER_WIN,
    BLUE_PLAYER_WIN,
    DRAW,
    END
};


class Engine {
    SDL_Surface *screen;
    int gameState;
  public:
    Engine();
    ~Engine();
    bool execute();
};

#endif
