#ifndef MAP_H
#define MAP_H

#include <SDL3/SDL.h>
#include <vector>
#include "Window.h"
// #include "Ext.h"

class Map {
public:
    Map();
    void drawMap();
    inline static float getTileSize() {
        return tileSize;
    }
    inline static std::vector<std::vector<int>> getMapGrid() {
        return mapGrid;
    }
private:
    inline static float tileSize = ((float)Window::getHeight()/10);
    inline static std::vector<std::vector<int>> mapGrid = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 4, 4, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0, 0, 1},
    {1, 0, 4, 0, 0, 0, 0, 4, 0, 2, 0, 2, 2, 2, 2, 0, 0, 3, 0, 0, 3, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 4, 0, 0, 0, 0, 4, 0, 2, 2, 2, 2, 0, 2, 0, 3, 0, 0, 0, 0, 3, 0, 1},
    {1, 0, 4, 4, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    SDL_FRect tile;
};

#endif