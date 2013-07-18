#ifndef ENGINE_H
#define ENGINE_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "events.h"

class Dots : public EventHandler {
  public:
    Dots();
    ~Dots();
    bool execute();
};

#endif