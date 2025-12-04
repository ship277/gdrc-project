#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL_main.h>
#include "Window.h"
#include "Player.h"
#include "Map.h"
// #include "Ext.h"

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

    // if (key_states[SDL_SCANCODE_TAB]) { // uncomment statement to simulate automap
        state->map.DrawMap();
        state->player.drawPlayer(state->player.GetDir());
    // }

    //  //  debug info
    // std::cout << state->player.cTile.x << "," << state->player.cTile.y << " - ";
    // if (state->map.mapGrid[state->player.cTile.y][state->player.cTile.x] > 0) 
    //     std::cout << "Wall" << std::endl;
    // else
    //     std::cout << "Space" << std::endl;

    // std::cout << state->player.nTile.x << "," << state->player.nTile.y << " - ";
    // if (state->map.mapGrid[state->player.nTile.y][state->player.nTile.x] > 0) 
    //     std::cout << "Wall" << std::endl;
    // else
    //     std::cout << "Space" << std::endl;

    std::cout << state->player.dir.x << "," << state->player.dir.y << std::endl;
    std::cout << state->player.angle << std::endl << "\n\n\n\n";

    SDL_RenderPresent(state->window.GetRenderer());
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* AppState, SDL_AppResult Result) {
    delete /* & */AppState; //  I don't know what the problem is but dereferencing 'AppState' all the way causes the exit code to be an error. it still works either way, but best not to touch it.
}
