#include "object.hpp"

Object::Object(int _id) : id(_id) {
    type = OBJECT;
    verts.clear();
    pos = {0, 0};
    vel = {0, 0};
    acc = {0, 0};

    if (DEBUG_OBJECT)
        printf("        [OBJECT] {init} %d Created \n", id);
}

Object::Object(int _id, SDL_FPoint _pos) : id(_id), pos(_pos) {
    vel = {0, 0};
    acc = {0, 0};

    if (DEBUG_OBJECT)
        printf("        [OBJECT] {init} %d Created at (%f, %f)\n", id, pos.x, pos.y);
}
Object::~Object() {}

void Object::events() {}
void Object::update() {}

vector<SDL_Vertex> *Object::render() {
    return &verts;
}

void Object::set_position(SDL_FPoint _pos) {
    int dx = pos.x - _pos.x;
    int dy = pos.y - _pos.y;

    for (int i = 0; i < verts.size(); i++) {
        verts[i].position.x -= dx;
        verts[i].position.y -= dy;
    }

    pos = _pos;
}


