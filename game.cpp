#include "game.h"

Game::Game()
{
    cursorX = -1;
    cursorY = -1;
    backgroundImg = loadImage("img/background.png");
    rDotImg = loadImage("img/red_dot.png");
    bDotImg = loadImage("img/blue_dot.png");
    rFillImg = loadImage("img/red_fill.png");
    bFillImg = loadImage("img/blue_fill.png");
    rLinesImg = loadImage("img/red_lines.png");
    bLinesImg = loadImage("img/blue_lines.png");
    rDotHoverImg = loadImage("img/red_dot.png");
    bDotHoverImg = loadImage("img/blue_dot.png");

    if (!backgroundImg || !rDotImg || !bDotImg || !rFillImg || !bFillImg || 
        !rLinesImg || !bLinesImg || !rDotHoverImg || !bDotHoverImg) {
        std::cerr << "Can not load images.";
        exit(1);
    }
    setScopes(rLinesScopes, bLinesScopes, rFillScopes, bFillScopes);
    SDL_SetAlpha(rDotHoverImg, SDL_SRCALPHA, 85);
    SDL_SetAlpha(bDotHoverImg, SDL_SRCALPHA, 85);
}

void Game::setScopes(SDL_Rect *rLinesScopes, 
                     SDL_Rect *bLinesScopes, 
                     SDL_Rect *rFillScopes, 
                     SDL_Rect *bFillScopes)
{
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            rFillScopes[i].w = rFillScopes[i].h = bFillScopes[i].w = bFillScopes[i].h = 20;
            rFillScopes[i].x = rFillScopes[i].x = j * 20;
            rFillScopes[i].y = rFillScopes[i].y = i * 20;
        }
    }
    for (i = 1; i <= 9; i++) {
        rLinesScopes[i].w = rLinesScopes[i].h = bLinesScopes[i].w = bLinesScopes[i].h = 40;
    }

    rLinesScopes[NO_LINE].x = bLinesScopes[NO_LINE].x = -1;
    rLinesScopes[NO_LINE].y = bLinesScopes[NO_LINE].y = -1;
    rLinesScopes[LEFT_UP].x = bLinesScopes[LEFT_UP].x = 0;
    rLinesScopes[LEFT_UP].y = bLinesScopes[LEFT_UP].y = 0;
    rLinesScopes[UP].x = bLinesScopes[UP].x = 40;
    rLinesScopes[UP].y = bLinesScopes[UP].y = 0;
    rLinesScopes[RIGHT_UP].x = bLinesScopes[RIGHT_UP].x = 80;
    rLinesScopes[RIGHT_UP].y = bLinesScopes[RIGHT_UP].y = 0;
    rLinesScopes[LEFT].x = bLinesScopes[LEFT].x = 0;
    rLinesScopes[LEFT].y = bLinesScopes[LEFT].y = 40;
    rLinesScopes[RIGHT].x = bLinesScopes[RIGHT].x = 80;
    rLinesScopes[RIGHT].y = bLinesScopes[RIGHT].y = 40;
    rLinesScopes[LEFT_DOWN].x = bLinesScopes[LEFT_DOWN].x = 0;
    rLinesScopes[LEFT_DOWN].y = bLinesScopes[LEFT_DOWN].y = 80;
    rLinesScopes[DOWN].x = bLinesScopes[DOWN].x = 40;
    rLinesScopes[DOWN].y = bLinesScopes[DOWN].y = 80;
    rLinesScopes[RIGHT_DOWN].x = bLinesScopes[RIGHT_DOWN].x = 80;   
    rLinesScopes[RIGHT_DOWN].y = bLinesScopes[RIGHT_DOWN].y = 80;
}

Game::~Game()
{
    SDL_FreeSurface(backgroundImg);
    SDL_FreeSurface(rDotImg);
    SDL_FreeSurface(bDotImg);
    SDL_FreeSurface(rFillImg);
    SDL_FreeSurface(bFillImg);
    SDL_FreeSurface(rLinesImg);
    SDL_FreeSurface(bLinesImg);
    SDL_FreeSurface(rDotHoverImg);
    SDL_FreeSurface(bDotHoverImg);
}

void Game::eventLButtonDown(int& gameState, int mX, int mY)
{
    int x, y;
    x = (mX + 10) / 20;
    y = (mY + 10) / 20;
    if (x && y && (x < FIELD_SIZE) && (y < FIELD_SIZE) && (field[y][x].dot == EMPTY_DOT)) {
        if (gameState == RED_PLAYER) {
            field[y][x].dot = RED_DOT;
            gameState = BLUE_PLAYER;
        } else if (gameState == BLUE_PLAYER) {
            field[y][x].dot = BLUE_DOT;
            gameState = RED_PLAYER;
        }
    }
}

void Game::eventMouseMove(int& gameState, int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle)
{
    int x, y;
    x = (mX + 10) / 20;
    y = (mY + 10) / 20;
    if (x && y && (x < FIELD_SIZE) && (y < FIELD_SIZE) && (field[y][x].dot == EMPTY_DOT) && 
        ((gameState == RED_PLAYER) || (gameState == BLUE_PLAYER))) {
        cursorX = x;
        cursorY = y;
    } else {
        cursorX = -1;
        cursorY = -1;
    }
}

void Game::eventExit(int& gameState) 
{ 
    gameState = END;
}

void Game::checkLines()
{

}

void Game::render(SDL_Surface *screen, int gameState)
{
    int i, j;
    applySurface(0, 0, backgroundImg, screen);

    if ((cursorX != -1) && (cursorY != -1)) {
        if (gameState == RED_PLAYER) {
            applySurface((cursorX * CELL_SIZE) - (rDotHoverImg->w / 2), (cursorY * CELL_SIZE) - (rDotHoverImg->h / 2), rDotHoverImg, screen);
        } else if (gameState == BLUE_PLAYER) {
            applySurface((cursorX * CELL_SIZE) - (bDotHoverImg->w / 2), (cursorY * CELL_SIZE) - (bDotHoverImg->h / 2), bDotHoverImg, screen);
        }
    }

    for (i = 0; i < FIELD_SIZE; i++) {
        for (j = 0; j < FIELD_SIZE; j++) {
            switch (field[i][j].dot) {
            case RED_DOT:
                if (field[i][j].lineDirection != NO_LINE) {
                    applySurface((j * CELL_SIZE) - 21, (i * CELL_SIZE) - 21, rLinesImg, screen, &rLinesScopes[field[i][j].lineDirection]);
                }
                applySurface((j * CELL_SIZE) - (rDotImg->w / 2), (i * CELL_SIZE) - (rDotImg->h / 2), rDotImg, screen);
                break;
            case BLUE_DOT:
                if (field[i][j].lineDirection != NO_LINE) {
                    applySurface((j * CELL_SIZE) - 21, (i * CELL_SIZE) - 21, bLinesImg, screen, &rLinesScopes[field[i][j].lineDirection]);
                }
                applySurface((j * CELL_SIZE) - (rDotImg->w / 2), (i * CELL_SIZE) - (rDotImg->h / 2), bDotImg, screen);
                break;
            }
        }
    }
}
