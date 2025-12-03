#ifndef MAP_H
#define MAP_H

#include <SDL3/SDL.h>
#include <vector>
#include "Window.h"
// #include "Ext.h"

class Map {
public:
    Map();
    void DrawMap();
    std::vector<std::vector<int>> mapGrid;
    SDL_FRect tile;
    inline static const float tileSize = ((float)Window::GetHeight()/10);
};

#endif