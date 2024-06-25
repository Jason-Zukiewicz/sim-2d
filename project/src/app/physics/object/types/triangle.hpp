#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "../object.hpp"

class Triangle : public Object {
public:
    float width;
    float height;

public:
    Triangle(int _id);
    Triangle(int _id, SDL_FPoint _pos);
    ~Triangle();

    void create_verts();

    void events();
    void update();
};

#endif