#ifndef WINDOW_H
#define WINDOW_H

#include <SDL3/SDL.h>
#include <iostream>

class Window {
public:
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

    inline static SDL_Window* GetWindow() {
        return window;
    }
    inline static SDL_Renderer* GetRenderer() {
        return renderer;
    }

    static int GetWidth() {
        return width;
    }
    static int GetHeight() {
        return height;
    }

private:
    inline static SDL_Window* window = nullptr;
    inline static SDL_Renderer* renderer = nullptr;
    static const int width = 1376, height = 576;
};


#endif