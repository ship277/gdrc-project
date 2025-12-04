#ifndef PLAYER_H
#define PLAYER_H

#include "Ext.h"
#include "Window.h"
#include "Map.h"

class Player {
public:
    Player();
    void drawPlayer(ext::FVec2 dir);
    ext::FVec2 GetDir() {
        return dir;
    }
    void HandleEvents(const bool* key_states, float elapsedFrameTime);
    //  temporary public for debugging in main; getter functions not intended to be added.
    ext::FVec2 pos, nextPos, dir;
    float angle;

private:
    inline static const float turnSpd = 450, speed = 300, diameter = 10, radius = diameter/2;
    inline static const ext::FVec2 initPos = {((float)Window::GetHeight()/2 + Map::GetTileSize()/2), ((float)Window::GetHeight()/2 + Map::GetTileSize()/2)};
    // ext::FVec2 pos, nextPos, dir;
    ext::IVec2 cTile, nTile;
    // float angle;
    SDL_FRect plr;
};

#endif