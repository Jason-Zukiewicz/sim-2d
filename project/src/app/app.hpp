#ifndef APP_HPP
#define APP_HPP

#include <SDL2/SDL.h>
#include <cstdlib>
#include <string>

#include "../utils/settings.hpp"
#include "events/event_handler.hpp"
#include "physics/physics_handler.hpp"

class App {
private:
    int window_width;
    int window_height;
    std::string window_title;
    bool is_running;
    bool is_paused;

    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;

    PhysicsHandler *pHandler;
    EventHandler *eHandler;

private:
    void events();
    void update();
    void render();

public:
    App();
    ~App();
    void run();
};

#endif