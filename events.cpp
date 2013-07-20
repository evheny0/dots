#include "events.h"

void EventHandler::inputEvent(SDL_Event event, int& gameState)
{
    switch (event.type) {
    case SDL_ACTIVEEVENT:
        switch (event.active.state) {
        case SDL_APPMOUSEFOCUS:
            if (event.active.gain) {
                eventMouseFocus(gameState);
            } else {
                eventMouseBlur(gameState);
            }
            break;

        case SDL_APPINPUTFOCUS:
            if (event.active.gain) {
                eventInputFocus(gameState);
            } else {
                eventInputBlur(gameState);
            }
            break;

        case SDL_APPACTIVE:
            if (event.active.gain) {
                eventRestore(gameState);
            } else {
                eventMinimize(gameState);
            }
            break;
        }
        break;

    case SDL_KEYDOWN:
        eventKeyDown(gameState, event.key.keysym.sym, event.key.keysym.mod, event.key.keysym.unicode);
        break;

    case SDL_KEYUP:
        eventKeyUp(gameState, event.key.keysym.sym, event.key.keysym.mod, event.key.keysym.unicode);
        break;

    case SDL_MOUSEMOTION:
        eventMouseMove(gameState, event.motion.x, event.motion.y, event.motion.xrel, event.motion.yrel, 
                    (event.motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0, 
                    (event.motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0, 
                    (event.motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
        break;

    case SDL_MOUSEBUTTONDOWN:
        switch (event.button.button) {
        case SDL_BUTTON_LEFT:
            eventLButtonDown(gameState, event.button.x, event.button.y);
            break;

        case SDL_BUTTON_RIGHT:
            eventRButtonDown(gameState, event.button.x, event.button.y);
            break;

        case SDL_BUTTON_MIDDLE:
            eventMButtonDown(gameState, event.button.x, event.button.y);
            break;
        }
        break;

    case SDL_MOUSEBUTTONUP:
        switch (event.button.button) {
        case SDL_BUTTON_LEFT:
            eventLButtonUp(gameState, event.button.x, event.button.y);
            break;

        case SDL_BUTTON_RIGHT:
            eventRButtonUp(gameState, event.button.x, event.button.y);
            break;

        case SDL_BUTTON_MIDDLE:
            eventMButtonUp(gameState, event.button.x, event.button.y);
            break;

        }
        break;

    case SDL_QUIT:
        eventExit(gameState);
        break;

    case SDL_VIDEORESIZE:
        eventResize(gameState, event.resize.w, event.resize.h);
        break;

    case SDL_VIDEOEXPOSE:
        eventExpose(gameState);
        break;
    }
}

void EventHandler::eventInputFocus(int& gameState) { }
void EventHandler::eventInputBlur(int& gameState) { }
void EventHandler::eventKeyDown(int& gameState, SDLKey sym, SDLMod mod, Uint16 unicode) { }
void EventHandler::eventKeyUp(int& gameState, SDLKey sym, SDLMod mod, Uint16 unicode) { }
void EventHandler::eventMouseFocus(int& gameState) { }
void EventHandler::eventMouseBlur(int& gameState) { }
void EventHandler::eventMouseMove(int& gameState, int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle) { }
void EventHandler::eventLButtonDown(int& gameState, int mX, int mY) { }
void EventHandler::eventLButtonUp(int& gameState, int mX, int mY) { }
void EventHandler::eventRButtonDown(int& gameState, int mX, int mY) { }
void EventHandler::eventRButtonUp(int& gameState, int mX, int mY) { }
void EventHandler::eventMButtonDown(int& gameState, int mX, int mY) { }
void EventHandler::eventMButtonUp(int& gameState, int mX, int mY) { }
void EventHandler::eventMinimize(int& gameState) { }
void EventHandler::eventRestore(int& gameState) { }
void EventHandler::eventResize(int& gameState, int w, int h) { }
void EventHandler::eventExpose(int& gameState) { }
void EventHandler::eventExit(int& gameState) { }
