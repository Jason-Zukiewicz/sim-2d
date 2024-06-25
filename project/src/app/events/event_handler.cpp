#include "event_handler.hpp"

EventHandler::EventHandler(bool *_is_running, bool *_is_paused) : is_running(_is_running), is_paused(_is_paused) {
}
EventHandler::~EventHandler() {
    // todo
}

void EventHandler::events(SDL_Event event) {
    switch (event.type) {
    case SDL_QUIT:
        *is_running = false;
        break;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_w:
            // Handle 'W' key press
            // printf("'W' key pressed\n");
            break;
        case SDLK_a:
            // Handle 'A' key press
            // printf("'A' key pressed\n");
            break;
        case SDLK_s:
            // Handle 'S' key press
            // printf("'S' key pressed\n");
            break;
        case SDLK_d:
            // Handle 'D' key press
            // printf("'D' key pressed\n");
            break;
        case SDLK_SPACE:
            // Handle Space key press

            *is_paused = !*is_paused;
            printf("[eHANDLER] Render is %s\n", *is_paused ? "PAUSED" : "RUNNING");
            break;
        case SDLK_q:
            // Handle 'Q' key press
            // printf("'Q' key pressed\n");
            *is_running = false;
            break;
        default:
            break;
        }
        break;
    case SDL_KEYUP:
        switch (event.key.keysym.sym) {
        case SDLK_w:
        case SDLK_a:
        case SDLK_s:
        case SDLK_d:
        case SDLK_SPACE:
        case SDLK_q:
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
void EventHandler::update() {
    // todo
}
void EventHandler::render() {
    // todo
}
