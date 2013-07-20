#ifndef INTERFACE_H
#define INTERFACE_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class Sidebar {
  public:
    Sidebar();
    ~Sidebar();
};

class Cursor {
    int x, y;
  public:
    Cursor();
    ~Cursor();
};

#endif
