#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "../../../utils/colors.hpp"
#include "../../../utils/settings.hpp"
#include <SDL2/SDL.h>
#include <cstdlib>
#include <string>
#include <vector>

#define DEBUG_OBJECT (AppSettings::DEBUG_MODE >= 2)

using std::vector;

enum ObjectType {
    OBJECT,
    RECT,
    CIRCLE,
    TRIANGLE,
};



class Object {
protected:
    bool *debug;
    int id;

    vector<SDL_Vertex> verts;
    SDL_FPoint vel, acc;

public:
    SDL_FPoint pos;
    ObjectType type;

protected:
public:
    Object(int _id);
    Object(int _id, SDL_FPoint _pos);
    virtual ~Object();

    void events();
    void update();
    vector<SDL_Vertex> *render();

    void set_position(SDL_FPoint _pos);
};

#endif