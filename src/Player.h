#ifndef PLAYER_H
#define PLAYER_H

#include "Ext.h"
#include "Window.h"
#include "Map.h"

class Player {
public:
    Player();
    void drawPlayer(ext::FVec2 dir);
    void handleEvents(const bool* key_states, float elapsedFrameTime);
    ext::FVec2 GetDir() {
        return dir;
    }

private:
    float turnSpd, speed, diameter, radius;
    inline static ext::FVec2 initPos = {((float)Window::getHeight()/2 + Map::getTileSize()/2), ((float)Window::getHeight()/2 + Map::getTileSize()/2)};
    ext::FVec2 pos, nextPos, dir;
    ext::IVec2 cTile, nTile;
    float angle;
    SDL_FRect plr;
};

#endif