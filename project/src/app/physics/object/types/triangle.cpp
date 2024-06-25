#include "triangle.hpp"

Triangle::Triangle(int _id) : Object(_id) {
    type = TRIANGLE;
    pos = {0, 0};
    width = 25;
    height = 50;

    create_verts();
}

Triangle::Triangle(int _id, SDL_FPoint _pos) : Object(_id, _pos) {
    type = TRIANGLE;
    pos = _pos;
    width = 25;
    height = 50;
    create_verts();
}

Triangle::~Triangle() {}

void Triangle::create_verts() {

    SDL_Color color = random_color();

    SDL_Vertex v1 = {SDL_FPoint{pos.x - width, pos.y + height},
                     color,
                     SDL_FPoint{0, 0}};

    SDL_Vertex v2 = {SDL_FPoint{pos.x, pos.y - height},
                     color,
                     SDL_FPoint{0, 0}};

    SDL_Vertex v3 = {SDL_FPoint{pos.x + width, pos.y + height},
                     color,
                     SDL_FPoint{0, 0}};

    verts.push_back(v1);
    verts.push_back(v2);
    verts.push_back(v3);
}

void Triangle::events() {}
void Triangle::update() {}
