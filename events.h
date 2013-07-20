#ifndef EVENTS_H
#define EVENTS_H

#include <SDL/SDL.h>

class EventHandler {
  public:
    virtual void inputEvent(SDL_Event event, int& gameState);
    virtual void eventInputFocus(int& gameState);
    virtual void eventInputBlur(int& gameState);
    virtual void eventKeyDown(int& gameState, SDLKey sym, SDLMod mod, Uint16 unicode);
    virtual void eventKeyUp(int& gameState, SDLKey sym, SDLMod mod, Uint16 unicode);
    virtual void eventMouseFocus(int& gameState);
    virtual void eventMouseBlur(int& gameState);
    virtual void eventMouseMove(int& gameState, int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle);
    virtual void eventLButtonDown(int& gameState, int mX, int mY);
    virtual void eventLButtonUp(int& gameState, int mX, int mY);
    virtual void eventRButtonDown(int& gameState, int mX, int mY);
    virtual void eventRButtonUp(int& gameState, int mX, int mY);
    virtual void eventMButtonDown(int& gameState, int mX, int mY);
    virtual void eventMButtonUp(int& gameState, int mX, int mY);
    virtual void eventMinimize(int& gameState);
    virtual void eventRestore(int& gameState);
    virtual void eventResize(int& gameState, int w, int h);
    virtual void eventExpose(int& gameState);
    virtual void eventExit(int& gameState);
};

#endif
