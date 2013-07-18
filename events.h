#ifndef EVENTS_H
#define EVENTS_H

#include <SDL/SDL.h>

class EventHandler {
  public:
    virtual void inputEvent(SDL_Event *Event);
    virtual void OnInputFocus();
    virtual void OnInputBlur();
    virtual void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
    virtual void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
    virtual void OnMouseFocus();
    virtual void OnMouseBlur();
    virtual void OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle);
    virtual void OnLButtonDown(int mX, int mY);
    virtual void OnLButtonUp(int mX, int mY);
    virtual void OnRButtonDown(int mX, int mY);
    virtual void OnRButtonUp(int mX, int mY);
    virtual void OnMButtonDown(int mX, int mY);
    virtual void OnMButtonUp(int mX, int mY);
    virtual void OnMinimize();
    virtual void OnRestore();
    virtual void OnResize(int w, int h);
    virtual void OnExpose();
    virtual void OnExit();
};

#endif
