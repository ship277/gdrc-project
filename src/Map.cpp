#include <SDL3/SDL.h>
#include <vector>
#include "Map.h"
#include "Window.h"
// #include "Ext.h"
Map::Map() {}
void Map::drawMap() {
    for (int y = 0; y < mapGrid.size(); y++) {
        for (int x = 0; x < mapGrid[y].size(); x++) {
            tile = {x * tileSize , y * tileSize, tileSize -1, tileSize -1};
            switch (mapGrid[y][x]) {
                case 1:
                    SDL_SetRenderDrawColor(Window::getRenderer(), 100, 100, 100, 255);
                    break;
                case 2:
                    SDL_SetRenderDrawColor(Window::getRenderer(), 255, 0, 0, 255);
                    break;
                case 3:
                    SDL_SetRenderDrawColor(Window::getRenderer(), 0, 255, 0, 255);
                    break;
                case 4:
                    SDL_SetRenderDrawColor(Window::getRenderer(), 0, 0, 255, 255);
                    break;
                case 0:
                    SDL_SetRenderDrawColor(Window::getRenderer(), 255, 255, 255, 255);
                    break;
            }
            SDL_RenderFillRect(Window::getRenderer(), &tile);
        }
    }
}
