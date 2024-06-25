#ifndef EH_HPP
#define EH_HPP

#include <SDL2/SDL.h>
#include <cstdlib>
#include <string>

class EventHandler {
private:
    bool *is_running;
    bool *is_paused;

public:
    EventHandler(bool *_is_running, bool *_is_paused);
    ~EventHandler();

    void events(SDL_Event event);
    void update();
    void render();
};

#endif