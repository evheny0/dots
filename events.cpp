#include "events.h"

void EventHandler::inputEvent(SDL_Event * Event)
{
    switch (Event->type) {
    case SDL_ACTIVEEVENT:
        switch (Event->active.state) {
        case SDL_APPMOUSEFOCUS:
            if (Event->active.gain) {
                OnMouseFocus();
            } else {
                OnMouseBlur();
            }
            break;

        case SDL_APPINPUTFOCUS:
            if (Event->active.gain) {
                OnInputFocus();
            } else {
                OnInputBlur();
            }
            break;

        case SDL_APPACTIVE:
            if (Event->active.gain) {
                OnRestore();
            } else {
                OnMinimize();
            }
            break;
        }
        break;

    case SDL_KEYDOWN:
        OnKeyDown(Event->key.keysym.sym, Event->key.keysym.mod, Event->key.keysym.unicode);
        break;

    case SDL_KEYUP:
        OnKeyUp(Event->key.keysym.sym, Event->key.keysym.mod, Event->key.keysym.unicode);
        break;

    case SDL_MOUSEMOTION:
        OnMouseMove(Event->motion.x, Event->motion.y, Event->motion.xrel, Event->motion.yrel, 
                    (Event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0, 
                    (Event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0, 
                    (Event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
        break;

    case SDL_MOUSEBUTTONDOWN:
        switch (Event->button.button) {
        case SDL_BUTTON_LEFT:
            OnLButtonDown(Event->button.x, Event->button.y);
            break;

        case SDL_BUTTON_RIGHT:
            OnRButtonDown(Event->button.x, Event->button.y);
            break;

        case SDL_BUTTON_MIDDLE:
            OnMButtonDown(Event->button.x, Event->button.y);
            break;
        }
        break;

    case SDL_MOUSEBUTTONUP:
        switch (Event->button.button) {
        case SDL_BUTTON_LEFT:
            OnLButtonUp(Event->button.x, Event->button.y);
            break;

        case SDL_BUTTON_RIGHT:
            OnRButtonUp(Event->button.x, Event->button.y);
            break;

        case SDL_BUTTON_MIDDLE:
            OnMButtonUp(Event->button.x, Event->button.y);
            break;

        }
        break;

    case SDL_QUIT:
        OnExit();
        break;

    case SDL_VIDEORESIZE:
        OnResize(Event->resize.w, Event->resize.h);
        break;

    case SDL_VIDEOEXPOSE:
        OnExpose();
        break;
    }
}

void EventHandler::OnInputFocus()
{

}

void EventHandler::OnInputBlur()
{

}

void EventHandler::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{

}

void EventHandler::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{

}

void EventHandler::OnMouseFocus()
{

}

void EventHandler::OnMouseBlur()
{

}

void EventHandler::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle)
{

}

void EventHandler::OnLButtonDown(int mX, int mY)
{

}

void EventHandler::OnLButtonUp(int mX, int mY)
{

}

void EventHandler::OnRButtonDown(int mX, int mY)
{

}

void EventHandler::OnRButtonUp(int mX, int mY)
{

}

void EventHandler::OnMButtonDown(int mX, int mY)
{

}

void EventHandler::OnMButtonUp(int mX, int mY)
{

}

void EventHandler::OnMinimize()
{

}

void EventHandler::OnRestore()
{

}

void EventHandler::OnResize(int w, int h)
{

}

void EventHandler::OnExpose()
{

}

void EventHandler::OnExit()
{

}
