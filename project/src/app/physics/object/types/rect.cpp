#include "rect.hpp"

Rect::Rect(int _id) : Object(_id) {
    type = RECT;

    pos = {250, 250};
    width = 50;
    height = 50;

    create_verts();
}

Rect::Rect(int _id, SDL_FPoint _pos) : Object(_id, _pos) {
    type = RECT;

    pos = _pos;
    width = 50;
    height = 50;

    create_verts();
}
Rect::~Rect() {}

void Rect::create_verts() {

    float left = pos.x - width;
    float right = pos.x + width;
    float top = pos.y - height;
    float bottom = pos.y + height;

    SDL_Color color = random_color();

    SDL_Vertex v1 = {SDL_FPoint{left, top},
                     color,
                     SDL_FPoint{0, 0}};

    SDL_Vertex v2 = {SDL_FPoint{right, top},
                     color,
                     SDL_FPoint{0, 0}};

    SDL_Vertex v3 = {SDL_FPoint{left, bottom},
                     color,
                     SDL_FPoint{0, 0}};

    SDL_Vertex u1 = {SDL_FPoint{right, top},
                     color,
                     SDL_FPoint{0, 0}};

    SDL_Vertex u2 = {SDL_FPoint{right, bottom},
                     color,
                     SDL_FPoint{0, 0}};

    SDL_Vertex u3 = {SDL_FPoint{left, bottom},
                     color,
                     SDL_FPoint{0, 0}};

    verts.push_back(v1);
    verts.push_back(v2);
    verts.push_back(v3);
    verts.push_back(u1);
    verts.push_back(u2);
    verts.push_back(u3);
}

void Rect::events() {}
void Rect::update() {}
