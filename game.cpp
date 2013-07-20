#include "game.h"

Game::Game()
{
    backgroundImg = loadImage("img/background.png");
    redDotImg = loadImage("img/red_dot.png");
    blueDotImg = loadImage("img/blue_dot.png");
    redFillImg = loadImage("img/red_fill.png");
    blueFillImg = loadImage("img/blue_fill.png");
    redLinesImg = loadImage("img/red_lines.png");
    blueLinesImg = loadImage("img/blue_lines.png");

    if (!backgroundImg || !redDotImg || !blueDotImg || !redFillImg || !blueFillImg || !redLinesImg || !blueLinesImg) {
        std::cerr << "Can not find images.";
        exit(1);
    }
    setScopes(redLinesScopes, blueLinesScopes, redFillScopes, blueFillScopes);
}

void Game::setScopes(SDL_Rect *redLinesScopes, 
                     SDL_Rect *blueLinesScopes, 
                     SDL_Rect *redFillScopes, 
                     SDL_Rect *blueFillScopes)
{
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            redFillScopes[i].w = redFillScopes[i].h = blueFillScopes[i].w = blueFillScopes[i].h = 20;
            redFillScopes[i].x = redFillScopes[i].x = j * 20;
            redFillScopes[i].y = redFillScopes[i].y = i * 20;
        }
    }
    for (i = 1; i <= 9; i++) {
        redLinesScopes[i].w = redLinesScopes[i].h = blueLinesScopes[i].w = blueLinesScopes[i].h = 40;
    }

    redLinesScopes[NO_LINE].x = blueLinesScopes[NO_LINE].x = -1;
    redLinesScopes[NO_LINE].y = blueLinesScopes[NO_LINE].y = -1;
    redLinesScopes[LEFT_UP].x = blueLinesScopes[LEFT_UP].x = 0;
    redLinesScopes[LEFT_UP].y = blueLinesScopes[LEFT_UP].y = 0;
    redLinesScopes[UP].x = blueLinesScopes[UP].x = 40;
    redLinesScopes[UP].y = blueLinesScopes[UP].y = 0;
    redLinesScopes[RIGHT_UP].x = blueLinesScopes[RIGHT_UP].x = 80;
    redLinesScopes[RIGHT_UP].y = blueLinesScopes[RIGHT_UP].y = 0;
    redLinesScopes[LEFT].x = blueLinesScopes[LEFT].x = 0;
    redLinesScopes[LEFT].y = blueLinesScopes[LEFT].y = 40;
    redLinesScopes[RIGHT].x = blueLinesScopes[RIGHT].x = 80;
    redLinesScopes[RIGHT].y = blueLinesScopes[RIGHT].y = 40;
    redLinesScopes[LEFT_DOWN].x = blueLinesScopes[LEFT_DOWN].x = 0;
    redLinesScopes[LEFT_DOWN].y = blueLinesScopes[LEFT_DOWN].y = 80;
    redLinesScopes[DOWN].x = blueLinesScopes[DOWN].x = 40;
    redLinesScopes[DOWN].y = blueLinesScopes[DOWN].y = 80;
    redLinesScopes[RIGHT_DOWN].x = blueLinesScopes[RIGHT_DOWN].x = 80;   
    redLinesScopes[RIGHT_DOWN].y = blueLinesScopes[RIGHT_DOWN].y = 80;
}

Game::~Game()
{
    SDL_FreeSurface(backgroundImg);
    SDL_FreeSurface(redDotImg);
    SDL_FreeSurface(blueDotImg);
    SDL_FreeSurface(redFillImg);
    SDL_FreeSurface(blueFillImg);
    SDL_FreeSurface(redLinesImg);
    SDL_FreeSurface(blueLinesImg);
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

void Game::eventExit(int& gameState) 
{ 
    gameState = END;
}

void Game::checkLines()
{

}

void Game::render(SDL_Surface *screen)
{
    int i, j;
    applySurface(0, 0, backgroundImg, screen);

    for (i = 0; i < FIELD_SIZE; i++) {
        for (j = 0; j < FIELD_SIZE; j++) {
            switch (field[i][j].dot) {
            case RED_DOT:
                if (field[i][j].lineDirection != NO_LINE) {
                    applySurface((j * CELL_SIZE) - 21, (i * CELL_SIZE) - 21, redLinesImg, screen, &redLinesScopes[field[i][j].lineDirection]);
                }
                applySurface((j * CELL_SIZE) - (redDotImg->w / 2), (i * CELL_SIZE) - (redDotImg->h / 2), redDotImg, screen);
                break;
            case BLUE_DOT:
                if (field[i][j].lineDirection != NO_LINE) {
                    applySurface((j * CELL_SIZE) - 21, (i * CELL_SIZE) - 21, blueLinesImg, screen, &redLinesScopes[field[i][j].lineDirection]);
                }
                applySurface((j * CELL_SIZE) - (redDotImg->w / 2), (i * CELL_SIZE) - (redDotImg->h / 2), blueDotImg, screen);
                break;
            }
        }
    }
}
