#ifndef ENTITY_H
#define ENTITY_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

enum DotValues { 
    EMPTY_DOT,
    RED_DOT,
    BLUE_DOT
};

enum LineDirections {
    NO_LINE,
    LEFT_UP,
    UP,
    RIGHT_UP,
    LEFT,
    RIGHT,
    LEFT_DOWN,
    DOWN,
    RIGHT_DOWN
};


class Cell {
  public:
    Cell();
    int dot;
    int lineDirection;
};

#endif
