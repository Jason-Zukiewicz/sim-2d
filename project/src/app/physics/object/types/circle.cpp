#include "circle.hpp"

Circle::Circle(int _id) : Object(_id) {
    type = CIRCLE;
    pos = {0, 0};

    create_verts();
}

Circle::Circle(int _id, SDL_FPoint _pos) : Object(_id, _pos) {
    type = CIRCLE;
    pos = _pos;
    
    create_verts();
}

Circle::~Circle() {}

void Circle::create_verts() {
    int segments = 12;
    radius = 50.0f; // Adjust as needed
    float angle = 2.0f * M_PI / segments;
    SDL_Color color = random_color();

    for (int i = 0; i < segments; i++) {
        float x1 = pos.x + cos(i * angle) * radius;
        float y1 = pos.y + sin(i * angle) * radius;
        float x2 = pos.x + cos((i + 1) * angle) * radius;
        float y2 = pos.y + sin((i + 1) * angle) * radius;

        SDL_Vertex v1 = {SDL_FPoint{x1, y1}, color, SDL_FPoint{0, 0}};
        SDL_Vertex v2 = {SDL_FPoint{x2, y2}, color, SDL_FPoint{0, 0}};
        SDL_Vertex v3 = {SDL_FPoint{pos.x, pos.y}, color, SDL_FPoint{0, 0}}; // Center of circle

        verts.push_back(v1);
        verts.push_back(v2);
        verts.push_back(v3);
    }
}

void Circle::events() {}
void Circle::update() {}
