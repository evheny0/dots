#include "engine.h"

int main(int argc, char *argv[])
{
    Engine app;
    return app.execute();
}

Engine::Engine()
{
    screen = screenInit();
    gameState = RED_PLAYER;
}

Engine::~Engine()
{
    SDL_Quit();
}

bool Engine::execute()
{
    Game game;
    SDL_Event event;
    while (gameState != END) {
        SDL_PollEvent(&event);
        game.inputEvent(event, gameState);
        game.checkLines();
        game.render(screen);

        if (SDL_Flip(screen) == -1) {
            return 1;
        }
    }
    return 0;
}
