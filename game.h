#ifndef GAME_H
#define GAME_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include "events.h"
#include "engine.h"
#include "entity.h"
#include "interface.h"
#include "graphics.h"

const int FIELD_SIZE = 20;
const int CELL_SIZE = 20;


class Game : public EventHandler {
    Cell field[FIELD_SIZE][FIELD_SIZE];

    SDL_Surface *backgroundImg;
    SDL_Surface *redDotImg;
    SDL_Surface *blueDotImg;
    SDL_Surface *redFillImg;
    SDL_Surface *blueFillImg;
    SDL_Surface *redLinesImg;
    SDL_Surface *blueLinesImg;

    SDL_Rect redFillScopes[5];
    SDL_Rect blueFillScopes[5];
    SDL_Rect redLinesScopes[10];
    SDL_Rect blueLinesScopes[10];

    Sidebar sidebar;
    Cursor cursor;
  public:
    Game();
    ~Game();
    void setScopes(SDL_Rect *redLinesScopes, SDL_Rect *blueLinesScopes, SDL_Rect *redFillScopes, SDL_Rect *blueFillScopes);
    void eventLButtonDown(int& gameState, int mX, int mY);
    void eventExit(int& gameState);
    void checkLines();
    void render(SDL_Surface *screen);
};

#endif
