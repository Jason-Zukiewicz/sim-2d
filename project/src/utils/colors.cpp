#include "colors.hpp"

static std::mt19937 engine(static_cast<unsigned int>(std::time(nullptr)));
static std::uniform_int_distribution<Uint8> dist_color(0, 255);
SDL_Color random_color() {
    Uint8 r = dist_color(engine), g = dist_color(engine), b = dist_color(engine);
    SDL_Color color = {r, g, b, 255};
    return color;
}