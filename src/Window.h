#ifndef WINDOW_H
#define WINDOW_H

#include <SDL3/SDL.h>

class Window {
public:
    Window();
    ~Window();
    static const int width = 1376, height = 576;
    void Update();
    SDL_Window* GetWindow();
    SDL_Renderer* GetRenderer();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif