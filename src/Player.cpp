#include <SDL3/SDL.h>
#include "Player.h"
#include "Window.h"

Player::Player()
    :   speed(300.0),
        pos{10.0, 10.0},
        dir{0, (-1)},
        plr{pos.x, pos.y, 10, 10}
{
}

void Player::HandleEvents(const bool* key_states, float elapsedFrameTime) {
    if (key_states[SDL_SCANCODE_W] && plr.y > 0)
        plr.y -= (speed * elapsedFrameTime);
    if (key_states[SDL_SCANCODE_A] && plr.x > 0)
        plr.x -= (speed * elapsedFrameTime);
    if (key_states[SDL_SCANCODE_S] && plr.y < (Window::height - plr.h))
        plr.y += (speed * elapsedFrameTime);
    if (key_states[SDL_SCANCODE_D] && plr.x < (Window::width - plr.w))
        plr.x += (speed * elapsedFrameTime);
}

SDL_FRect& Player::GetPlr() {
    return plr;
}
