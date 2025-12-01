#include <SDL3/SDL.h>
#include <iostream>
#include "Window.h"

Window::Window()
    :   window(nullptr),
        renderer(nullptr)
{
    SDL_CreateWindowAndRenderer(
    "tutorial",
    width, height,
    SDL_WINDOW_OPENGL,
    &window, &renderer
    );
}

void Window::Update() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

Window::~Window() {
    if (window && SDL_WasInit(SDL_INIT_VIDEO)) {
        SDL_DestroyWindow(window);
    } else {
        std::cout << "Skipping SDL_DestroyWindow\n";
    }
}

SDL_Window* Window::GetWindow() {
    return window;
}
SDL_Renderer* Window::GetRenderer() {
    return renderer;
}

