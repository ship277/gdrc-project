#include <SDL3/SDL.h>
#include "Player.h"
#include "Map.h"
#include "Window.h"

Map map;

Player::Player()
    :   pos{((float)Window::height/2), ((float)Window::height/2)},
        plr{pos.x - radius, pos.y - radius, diameter, diameter}
{
}
// movement. real-time next tile prediction if it's a wall or empty space.
void Player::HandleEvents(const bool* key_states, float elapsedFrameTime) {
    if (key_states[SDL_SCANCODE_W] && pos.y > 0) {
            cTile = {(int)(pos.x/map.tileSize), (int)(pos.y/map.tileSize)};
            nTile = {(int)(pos.x/map.tileSize), (int)((pos.y -1 - radius)/map.tileSize)};
            if (map.mapGrid[nTile.y ][nTile.x] == 0) {
                pos.y -= (speed * elapsedFrameTime);
                plr.y = pos.y - radius;
            }
    }
    if (key_states[SDL_SCANCODE_A] && pos.x > 0) {
            cTile = {(int)(pos.x/map.tileSize), (int)(pos.y/map.tileSize)};
            nTile = {(int)((pos.x -1 - radius)/map.tileSize), (int)(pos.y/map.tileSize)};
            if (map.mapGrid[nTile.y][nTile.x] == 0) {
                pos.x -= (speed * elapsedFrameTime);
                plr.x = pos.x - radius;
            }
    }
    if (key_states[SDL_SCANCODE_S] && pos.y < (Window::height - plr.h)) {
            cTile = {(int)(pos.x/map.tileSize), (int)(pos.y/map.tileSize)};
            nTile = {(int)(pos.x/map.tileSize), (int)((pos.y +1 + radius)/map.tileSize)};
            if (map.mapGrid[nTile.y][nTile.x] == 0) {
                pos.y += (speed * elapsedFrameTime);
                plr.y = pos.y - radius;
            }
    }
    if (key_states[SDL_SCANCODE_D] && pos.x < (Window::width - plr.w)) {
            cTile = {(int)(pos.x/map.tileSize), (int)(pos.y/map.tileSize)};
            nTile = {(int)((pos.x +1 + radius)/map.tileSize), (int)(pos.y/map.tileSize)};
            if (map.mapGrid[nTile.y][nTile.x] == 0) {
                pos.x += (speed * elapsedFrameTime);
                plr.x = pos.x - radius;
            }
    }
}

void Player::drawPlayer() {
    SDL_SetRenderDrawColor(Window::GetRenderer(), 0, 255, 0, 255);
    SDL_RenderFillRect(Window::GetRenderer(), &plr);
}
