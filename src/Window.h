#ifndef WINDOW_H
#define WINDOW_H

#include <SDL3/SDL.h>
#include <iostream>

class Window {
public:
    inline static const int width = 1376, height = 576;
    Window() {
        SDL_CreateWindowAndRenderer(
            "tutorial",
            width, height,
            SDL_WINDOW_OPENGL,
            &window, &renderer
        );
    }

    void Update() {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
    }

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    ~Window() {
        if (window && SDL_WasInit(SDL_INIT_VIDEO)) {
            SDL_DestroyWindow(window);
        } else {
            std::cout << "Skipping SDL_DestroyWindow\n";
        }
    }

    static SDL_Window* GetWindow() {
        return window;
    }
    static SDL_Renderer* GetRenderer() {
        return renderer;
    }

private:
    static SDL_Window* window;
    static SDL_Renderer* renderer;
};


#endif