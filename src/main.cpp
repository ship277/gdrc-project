#include <SDL3/SDL_events.h>
#include <SDL3/SDL_scancode.h>
#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "Window.h"
#include "Player.h"
#include "Map.h"

struct ProgramState {
    Window window;
    Player player;
    Map map;
    Uint64 PreviousFrame = 0;
};

SDL_Texture* texture;

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
    
    const bool *key_states = SDL_GetKeyboardState(NULL);
    SDL_Renderer* renderer = state->window.GetRenderer();

    float elapsedFrameTime = (SDL_GetTicks() - state->PreviousFrame) / 1000.0f;
    state->PreviousFrame = SDL_GetTicks();

    state->player.HandleEvents(key_states, elapsedFrameTime);

    state->window.Update();

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &state->player.plr);

    SDL_RenderPresent(state->window.GetRenderer());
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* AppState, SDL_AppResult Result) {
    delete AppState;
}
