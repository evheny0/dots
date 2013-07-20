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
    int cursorX, cursorY;

    SDL_Surface *backgroundImg;
    SDL_Surface *rDotImg;
    SDL_Surface *bDotImg;
    SDL_Surface *rFillImg;
    SDL_Surface *bFillImg;
    SDL_Surface *rLinesImg;
    SDL_Surface *bLinesImg;
    SDL_Surface *rDotHoverImg;
    SDL_Surface *bDotHoverImg;

    SDL_Rect rFillScopes[5];
    SDL_Rect bFillScopes[5];
    SDL_Rect rLinesScopes[10];
    SDL_Rect bLinesScopes[10];

    Sidebar sidebar;
  public:
    Game();
    ~Game();
    void setScopes(SDL_Rect *rLinesScopes, SDL_Rect *bLinesScopes, SDL_Rect *rFillScopes, SDL_Rect *bFillScopes);
    void eventLButtonDown(int& gameState, int mX, int mY);
    void eventMouseMove(int& gameState, int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle);
    void eventExit(int& gameState);
    void checkLines();
    void render(SDL_Surface *screen, int gameState);
};

#endif
