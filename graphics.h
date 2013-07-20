#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <iostream>
#include <string>

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 401;
const int SCREEN_BPP = 32;

SDL_Surface *screenInit();
SDL_Surface *loadImage(std::string filename);
void applySurface(int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect *clip = NULL);

#endif
