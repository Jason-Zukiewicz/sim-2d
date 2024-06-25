#ifndef CH_HPP
#define CH_HPP

#include "../../utils/settings.hpp"
#include "object/object.hpp"
#include "object/types/circle.hpp"
#include "object/types/rect.hpp"
#include "object/types/triangle.hpp"

#include <SDL2/SDL.h>
#include <cstdlib>
#include <vector>
using std::vector;

#define DEBUG_CollisionHandler (AppSettings::DEBUG_MODE >= 1)

class CollisionHandler {
private:
    bool *is_running;
    int object_count;
    vector<Object *> objects;

public:
    CollisionHandler(bool *_is_running);
    ~CollisionHandler();

    void update(vector<Object *> *_objects);

private:
    void GJK(Object *_obj1, Object *_obj2);

    // # Screen Bounds
    void object_type_splitter(Object *_obj);
    void check_screen_bounds(Object *_obj);
    void check_screen_bounds(Rect *_rect);

    void check_screen_bounds(Circle *_circle);

    void check_screen_bounds(Triangle *_tri);

    // # Collision Detection
    void object_type_splitter(Object *_obj1, Object *_obj2);
    bool check_collision(Object *_objA, Object *_objB);
    bool check_collision(Object *_objA, Rect *_rectB);
    bool check_collision(Object *_objA, Circle *_circleB);
    bool check_collision(Object *_obj1, Triangle *_triB);

    bool check_collision(Rect *_rectA, Rect *_rectB);
    bool check_collision(Rect *_rectA, Circle *_circleB);
    bool check_collision(Rect *_rectA, Triangle *_triB);

    bool check_collision(Circle *_circleA, Circle *_circleB);
    bool check_collision(Circle *_circleA, Triangle *_triB);

    bool check_collision(Triangle *_triA, Triangle *_triB);
};

#endif