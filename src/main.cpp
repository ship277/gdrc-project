#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <bits/stdc++.h>
#include "Window.h"

struct ProgramState {
    Window window;
    Uint64 PreviousFrame = 0;
};

SDL_Texture* texture;
SDL_FRect shape;

SDL_AppResult SDL_AppInit(void** AppState, int, char**) {
    SDL_Init(SDL_INIT_VIDEO);

    ProgramState* state = new ProgramState();
    state->PreviousFrame = SDL_GetTicks();
    *AppState = state;

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* AppState, SDL_Event* e) {
    ProgramState* state = static_cast<ProgramState*>(AppState);

    if (e->type == SDL_EVENT_QUIT)
        return SDL_APP_SUCCESS;

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* AppState) {
    ProgramState* state = static_cast<ProgramState*>(AppState);
    state->window.Update(texture, shape);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* AppState, SDL_AppResult Result) {
    delete AppState;
}
