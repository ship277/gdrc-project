#include <SDL3/SDL.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_scancode.h>
#include <cmath>
#include "Ext.h"
#include "Player.h"
#include "Map.h"
#include "Window.h"

Map map;

Player::Player()
    :   pos{((float)Window::GetHeight()/2), ((float)Window::GetHeight()/2)},
        plr{pos.x - radius, pos.y - radius, diameter, diameter}
{
}
// movement. real-time next tile prediction if it's a wall or empty space.
void Player::HandleEvents(const bool* key_states, float elapsedFrameTime) {
    if (key_states[SDL_SCANCODE_W]) {
            nTile = {(int)((pos.x + dir.x * (radius+1)) / map.tileSize), (int)((pos.y + dir.y * (radius+1)) / map.tileSize)};
            if (map.mapGrid[nTile.y][nTile.x] == 0) {
                pos += dir * speed * elapsedFrameTime;
                plr.y = pos.y - radius;
                plr.x = pos.x - radius;
            }
    }
    if (key_states[SDL_SCANCODE_A]) {
        angle -= ((ext::pi/360) * turnSpd * elapsedFrameTime);
        dir = {std::cos(angle), std::sin(angle)};
    }
    if (key_states[SDL_SCANCODE_S]) {
            nTile = {(int)((pos.x - dir.x * (radius+1)) / map.tileSize), (int)((pos.y - dir.y * (radius+1)) / map.tileSize)};
            if (map.mapGrid[nTile.y][nTile.x] == 0) {
                pos -= dir * speed * elapsedFrameTime;
                plr.y = pos.y - radius;
                plr.x = pos.x - radius;
            }
    }
    if (key_states[SDL_SCANCODE_D]) {
        angle += ((ext::pi/360) * turnSpd * elapsedFrameTime);
        dir = {std::cos(angle), std::sin(angle)};
    }
    if (key_states[SDL_SCANCODE_ESCAPE]) {
        pos = {(float)Window::GetHeight()/2, (float)Window::GetHeight()/2};
        plr.y = pos.y - radius;
        plr.x = pos.x - radius;
        
    }
}

void Player::drawPlayer(ext::FVec2 dir) {
    SDL_SetRenderDrawColor(Window::GetRenderer(), 255, 0, 255, 255);
    SDL_RenderFillRect(Window::GetRenderer(), &plr);
    SDL_RenderLine(Window::GetRenderer(), pos.x, pos.y, pos.x + dir.x * 20, pos.y + dir.y * 20);
}
