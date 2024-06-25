#ifndef COLORS_H
#define COLORS_H

#include <SDL2/SDL.h>
#include <ctime>
#include <random>

const SDL_Color RED = {255, 0, 0, 255};
const SDL_Color GREEN = {0, 255, 0, 255};
const SDL_Color BLUE = {0, 0, 255, 255};
const SDL_Color YELLOW = {255, 255, 0, 255};
const SDL_Color WHITE = {255, 255, 255, 255};
const SDL_Color BLACK = {0, 0, 0, 255};

SDL_Color random_color();

#endif
