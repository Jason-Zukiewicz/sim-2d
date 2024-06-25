#include "physics_handler.hpp"
#include <cstdio>

PhysicsHandler::PhysicsHandler(bool *_is_running) : is_running(_is_running), cHandler(is_running) {
    objects.clear();
    object_count = 0;
}
PhysicsHandler::~PhysicsHandler() {
    for (int i = 0; i < objects.size(); i++) {
        delete (objects[i]);
    }
}

void PhysicsHandler::events(SDL_Event _event) {
    switch (_event.type) {
    case SDL_KEYDOWN:
        switch (_event.key.keysym.sym) {
        case SDLK_SPACE:
            if (DEBUG_PhysicsHandler)
                printf("    [pHANDLER] {key} Space \n");
            CreateObject();
            break;
        case SDLK_r:
            if (DEBUG_PhysicsHandler)
                printf("    [pHANDLER] {key} R \n");
            CreateRect();
            break;
        case SDLK_t:
            if (DEBUG_PhysicsHandler)
                printf("    [pHANDLER] {key} T \n");
            CreateTriangle();
            break;
        case SDLK_y:
            if (DEBUG_PhysicsHandler)
                printf("    [pHANDLER] {key} T \n");
            CreateCircle();
            break;
        default:
            break;
        }
        break;
    case SDL_MOUSEBUTTONDOWN:
        switch (_event.button.button) {
        case SDL_BUTTON_LEFT:
            if (DEBUG_PhysicsHandler)
                printf("    [pHANDLER] {mouse} Left  Click (%d, %d)\n", _event.button.x, _event.button.y);
            CreateCircle(_event.button.x, _event.button.y);
            break;
        case SDL_BUTTON_RIGHT:
            if (DEBUG_PhysicsHandler)
                printf("    [pHANDLER] {mouse} Right Click (%d, %d)\n", _event.button.x, _event.button.y);
            CreateRect(_event.button.x, _event.button.y);
            break;
        case SDL_BUTTON_MIDDLE:
            if (DEBUG_PhysicsHandler)
                printf("    [pHANDLER] {mouse} Right Click (%d, %d)\n", _event.button.x, _event.button.y);
            CreateTriangle(_event.button.x, _event.button.y);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void PhysicsHandler::update() {
    for (int i = 0; i < objects.size(); i++) {
        objects[i]->update();
    }
    cHandler.update(&objects);
}

vector<Object *> *PhysicsHandler::render() {
    return &objects;
}

/* #region      ---------------------------------------------------- [ EVENTS ] --------------------------------------- */

void PhysicsHandler::CreateObject() {
    objects.push_back(new Object(object_count++));
}
void PhysicsHandler::CreateRect() {
    objects.push_back(new Rect(object_count++));
}
void PhysicsHandler::CreateRect(float _x, float _y) {
    objects.push_back(new Rect(object_count++, SDL_FPoint{_x, _y}));
}
void PhysicsHandler::CreateCircle() {
    objects.push_back(new Circle(object_count++));
}
void PhysicsHandler::CreateCircle(float _x, float _y) {
    objects.push_back(new Circle(object_count++, SDL_FPoint{_x, _y}));
}
void PhysicsHandler::CreateTriangle() {
    objects.push_back(new Triangle(object_count++));
}

void PhysicsHandler::CreateTriangle(float _x, float _y) {
    objects.push_back(new Triangle(object_count++, SDL_FPoint{_x, _y}));
}

/* #endregion   ---------------------------------------------------- [ EVENTS ] ---------------------------------------*/