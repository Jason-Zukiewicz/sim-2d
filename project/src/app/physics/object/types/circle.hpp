#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "../object.hpp"

class Circle : public Object {

public:
    float radius;

private: 
    void create_verts();

public:
    Circle(int _id);
    Circle(int _id, SDL_FPoint _pos);
    ~Circle();

    void events();
    void update();

    
};

#endif