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
    inline static const float GetTileSize() {
        return tileSize;
    }
    std::vector<std::vector<int>> GetMapGrid() {
        return mapGrid;
    }
private:
    inline static const float tileSize = ((float)Window::GetHeight()/10);
    std::vector<std::vector<int>> mapGrid;
    SDL_FRect tile;
};

#endif