#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>
#include "Ext.h"

class Player {
public:
    Player();
    void drawPlayer();
    void HandleEvents(const bool* key_states, float elapsedFrameTime);

    float speed = 300, diameter = 10, radius = diameter/2;
    ext::Vec2 pos, nextPos;
    ext::iVec2 cTile, nTile;
    SDL_FRect plr;
};

#endif