#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_assert.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_scancode.h>

class Player {
public:
    struct Vec2 {
        float x;
        float y;
    };

    Vec2 plrPos{10.0, 10.0};
    Vec2 plrDir;
    SDL_FRect plr{plrPos.x, plrPos.y, 10, 10};
    float speed = 200.0;

    void HandleEvents(const bool* key_states, float elapsedFrameTime) {
        if (key_states[SDL_SCANCODE_W] && plr.y > 0)
            plr.y -= (speed * elapsedFrameTime);
        if (key_states[SDL_SCANCODE_A] && plr.x > 0)
            plr.x -= (speed * elapsedFrameTime);
        if (key_states[SDL_SCANCODE_S] && plr.y < (540 - plr.w))
            plr.y += (speed * elapsedFrameTime);
        if (key_states[SDL_SCANCODE_D] && plr.x < (960 - plr.w))
            plr.x += (speed * elapsedFrameTime);
    }
};
