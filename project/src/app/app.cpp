#include "app.hpp"
App::App() {

    // # Get Environment Variables
    window_width = AppSettings::WINDOW_WIDTH;
    window_height = AppSettings::WINDOW_HEIGHT;
    window_title = AppSettings::WINDOW_TITLE;

    // # Set up Window & Renderer
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        exit(1);
    }

    sdl_window = SDL_CreateWindow(window_title.c_str(),
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  window_width, window_height,
                                  SDL_WINDOW_SHOWN);

    if (!sdl_window) {
        SDL_Quit();
        exit(2);
    }

    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);

    // # Set up Handlers
    pHandler = new PhysicsHandler(&is_running);
    eHandler = new EventHandler(&is_running, &is_paused);

    // # IF everything is okay, run the game
    is_running = true;
    is_paused = false;
}

App::~App() {
    SDL_DestroyRenderer(sdl_renderer);
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();

    delete (pHandler);
    delete (eHandler);
}

void App::events() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        eHandler->events(event);
        pHandler->events(event);
    }
}

void App::update() {
    pHandler->update();
}
void App::render() {

    SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
    SDL_RenderClear(sdl_renderer);

    //$ Render all objects
    vector<Object *> *objects = pHandler->render();
    if (objects != nullptr) {
        for (Object *object : *objects) {
            vector<SDL_Vertex> *verts = object->render();
            if (verts != nullptr) {
                SDL_RenderGeometry(sdl_renderer, nullptr, verts->data(), verts->size(), nullptr, 0);
            }
        }
    }

    SDL_RenderPresent(sdl_renderer);
    SDL_Delay(16); // ~60 FPS
}

void App::run() {
    printf("====================================================================================================\n");
    printf("Running with Debug Mode: %i \n", AppSettings::DEBUG_MODE);
    while (is_running) {
        events();
        if (is_paused)
            update();
        render();
    }
}
