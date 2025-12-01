#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>
#include "Ext.h"

class Player {
public:
    Player();
    void HandleEvents(const bool* key_states, float elapsedFrameTime);
    SDL_FRect &GetPlr();
    ext::Vec2 dir;

private:
    float speed;
    ext::Vec2 pos;
    SDL_FRect plr;
};

#endif