#ifndef RECT_HPP
#define RECT_HPP

#include "../object.hpp"

class Rect : public Object {
public:
    float width;
    float height;

private:
    void create_verts();

public:
    Rect(int _id);
    Rect(int _id, SDL_FPoint _pos);
    ~Rect();

    void events();
    void update();
};

#endif