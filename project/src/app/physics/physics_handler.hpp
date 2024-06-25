#ifndef PH_HPP
#define PH_HPP

#include "../../utils/settings.hpp"
#include "collision_handler.hpp"
#include "object/object.hpp"
#include "object/types/circle.hpp"
#include "object/types/rect.hpp"
#include "object/types/triangle.hpp"
#include <SDL2/SDL.h>
#include <cstdlib>
#include <string>
#include <vector>
using std::vector;

#define DEBUG_PhysicsHandler (AppSettings::DEBUG_MODE >= 1)

class PhysicsHandler {
private:
    bool *is_running;
    int object_count;
    vector<Object *> objects;

    CollisionHandler cHandler;

public:
private:
    void CreateObject();
    void CreateRect();
    void CreateRect(float _x, float _y);
    void CreateCircle();
    void CreateCircle(float _x, float _y);
    void CreateTriangle();
    void CreateTriangle(float _x, float _y);

public:
    PhysicsHandler(bool *_is_running);
    ~PhysicsHandler();

    void events(SDL_Event _event);
    void update();
    vector<Object *> *render();
};

#endif