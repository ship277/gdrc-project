#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <vector>
#include "Map.h"
#include "Window.h"
// #include "Ext.h"

Map::Map() 
    : mapGrid {
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
    }
{
}

void Map::DrawMap() {
    for (int y = 0; y < mapGrid.size(); y++) {
        for (int x = 0; x < mapGrid[y].size(); x++) {
            tile = {x * tileSize , y * tileSize, tileSize -1, tileSize -1};
            switch (mapGrid[y][x]) {
                case 1:
                    SDL_SetRenderDrawColor(Window::GetRenderer(), 100, 100, 100, 255);
                    break;
                case 2:
                    SDL_SetRenderDrawColor(Window::GetRenderer(), 255, 0, 0, 255);
                    break;
                case 3:
                    SDL_SetRenderDrawColor(Window::GetRenderer(), 0, 255, 0, 255);
                    break;
                case 4:
                    SDL_SetRenderDrawColor(Window::GetRenderer(), 0, 0, 255, 255);
                    break;
                case 0:
                    SDL_SetRenderDrawColor(Window::GetRenderer(), 255, 255, 255, 255);
                    break;
            }
            SDL_RenderFillRect(Window::GetRenderer(), &tile);
        }
    }
}
