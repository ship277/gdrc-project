#include <SDL3/SDL.h>
#include <cmath>
#include "Ext.h"
#include "Player.h"
#include "Map.h"
#include "Window.h"

Player::Player()
    :   pos(initPos),
        plr{pos.x - radius, pos.y - radius, diameter, diameter},
        dir{1, 0},
        angle(0.0),
        turnSpd(450),
        speed(300),
        diameter(10),
        radius(diameter/2)
{
}
// movement. real-time next tile prediction if it's a wall or empty space.
void Player::handleEvents(const bool* key_states, float elapsedFrameTime) {
    //  idk if this is even necessary, i was just afraid of it growing too big if you keep spinning.
    if (angle >= ext::pi * 2 || angle <= -ext::pi * 2) {
        angle = 0.0;
    }
    if (key_states[SDL_SCANCODE_W]) {
            nTile = {(int)((pos.x + dir.x * (radius+1)) / Map::getTileSize()), (int)((pos.y + dir.y * (radius+1)) / Map::getTileSize())};
            if (Map::getMapGrid()[nTile.y][nTile.x] == 0) {
                pos += dir * speed * elapsedFrameTime;
                plr = {pos.x - radius, pos.y - radius, diameter, diameter};
            }
    }
    if (key_states[SDL_SCANCODE_A]) {
        angle -= ((ext::pi/360) * turnSpd * elapsedFrameTime);
        dir = {std::cos(angle), std::sin(angle)};
    }
    if (key_states[SDL_SCANCODE_S]) {
            nTile = {(int)((pos.x - dir.x * (radius+1)) / Map::getTileSize()), (int)((pos.y - dir.y * (radius+1)) / Map::getTileSize())};
            if (Map::getMapGrid()[nTile.y][nTile.x] == 0) {
                pos -= dir * speed * elapsedFrameTime;
                plr = {pos.x - radius, pos.y - radius, diameter, diameter};
            }
    }
    if (key_states[SDL_SCANCODE_D]) {
        angle += ((ext::pi/360) * turnSpd * elapsedFrameTime);
        dir = {std::cos(angle), std::sin(angle)};
    }
    if (key_states[SDL_SCANCODE_ESCAPE]) {
        *this = Player();
    }
}

//  cheatsheet for dir vector:
//   0, -1      up
//   1,  0      right
//   0,  1      down
//  -1,  0      left
//  top-left:       negative
//  bottom-right:   positive
//  top/bottom:     bigger |y| value
//  right/left:     bigger |X| value

void Player::drawPlayer(ext::FVec2 dir) {
    SDL_SetRenderDrawColor(Window::getRenderer(), 255, 0, 255, 255);
    SDL_RenderFillRect(Window::getRenderer(), &plr);
    SDL_RenderLine(Window::getRenderer(), pos.x, pos.y, pos.x + dir.x * 20, pos.y + dir.y * 20);
}
