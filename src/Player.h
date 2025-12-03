#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>
#include "Ext.h"

class Player {
public:
    Player();
    void drawPlayer(ext::FVec2 dir);
    ext::FVec2 GetDir() {
        return dir;
    }
    void HandleEvents(const bool* key_states, float elapsedFrameTime);

private:
    inline static const float turnSpd = 450, speed = 300, diameter = 10, radius = diameter/2;
    ext::FVec2 pos, nextPos, dir{0, -1};
    ext::IVec2 cTile, nTile;
    float angle = 0.0;
    SDL_FRect plr;
};

#endif