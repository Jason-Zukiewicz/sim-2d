#include "collision_handler.hpp"
#define DEBUG_CollisionHandler (AppSettings::DEBUG_MODE >= 1)

CollisionHandler::CollisionHandler(bool *_is_running) : is_running(_is_running) {}
CollisionHandler::~CollisionHandler() {}

void CollisionHandler::update(vector<Object *> *_objects) {
    size_t size = _objects->size();

    //$ Collision
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (i != j) {
                object_type_splitter((*_objects)[i], (*_objects)[j]);
            }
        }
    }

    //$ Screen Bounds
    for (int i = 0; i < size; i++) {
        object_type_splitter((*_objects)[i]);
    }
}
/* #region  --------------------------------- [ Main Steps ] -----------------------------------*/

/* #endregion ------------------------------- [ Main Steps ] -----------------------------------*/

/* #region  --------------------------------- [ Check Screen Bounds ] -----------------------------------*/

void CollisionHandler::object_type_splitter(Object *_obj) {
    ObjectType type = _obj->type;

    switch (type) {
    case OBJECT:
        check_screen_bounds(_obj);
        break;
    case RECT:
        check_screen_bounds(dynamic_cast<Rect *>(_obj));
        break;
    case CIRCLE:
        check_screen_bounds(dynamic_cast<Circle *>(_obj));
        break;
    case TRIANGLE:
        check_screen_bounds(dynamic_cast<Triangle *>(_obj));
        break;
    }
}

void CollisionHandler::check_screen_bounds(Object *_obj) {}

void CollisionHandler::check_screen_bounds(Rect *_rect) {
    int screen_width = AppSettings::WINDOW_WIDTH;
    int screen_height = AppSettings::WINDOW_HEIGHT;

    SDL_FPoint pos = _rect->pos;
    float width = _rect->width;
    float height = _rect->height;

    float left = pos.x;
    float right = pos.x + width;
    float top = pos.y;
    float bottom = pos.y + height;

    bool is_out_of_bounds = false;

    if (left < 0) {
        pos.x = width;
        is_out_of_bounds = true;
    } else if (right > screen_width) {
        pos.x = screen_width - width;
        is_out_of_bounds = true;
    }

    if (top < 0) {
        pos.y = height / 2;
        is_out_of_bounds = true;
    } else if (bottom > screen_height) {
        pos.y = screen_height - height / 2;
        is_out_of_bounds = true;
    }

    if (is_out_of_bounds) {
        
        _rect->set_position(pos);
    }
}

void CollisionHandler::check_screen_bounds(Circle *_circle) {

    int screen_width = AppSettings::WINDOW_WIDTH;
    int screen_height = AppSettings::WINDOW_HEIGHT;

    SDL_FPoint pos = _circle->pos;
    float radius = _circle->radius;

    float left = pos.x - radius;
    float right = pos.x + radius;
    float top = pos.y - radius;
    float bottom = pos.y + radius;

    bool is_out_of_bounds = false;

    if (left < 0) {
        pos.x = radius;
        is_out_of_bounds = true;
    } else if (right > screen_width) {
        pos.x = screen_width - radius;
        is_out_of_bounds = true;
    }

    if (top < 0) {
        pos.y = radius;
        is_out_of_bounds = true;
    } else if (bottom > screen_height) {
        pos.y = screen_height - radius;
        is_out_of_bounds = true;
    }

    if (is_out_of_bounds) {
        _circle->set_position(pos);
    }
}

void CollisionHandler::check_screen_bounds(Triangle *_tri) {
    int screen_width = AppSettings::WINDOW_WIDTH;
    int screen_height = AppSettings::WINDOW_HEIGHT;
    bool is_out_of_bounds = false;

    SDL_FPoint pos = _tri->pos;
    vector<SDL_Vertex> *verts = _tri->render();

    float dx = 0;
    float dy = 0;

    for (SDL_Vertex &vert : *verts) {
        SDL_FPoint pos = vert.position;

        if (pos.x < 0) {
            dx = -pos.x;
            is_out_of_bounds = true;
        } else if (pos.x > screen_width) {
            is_out_of_bounds = true;
            dx = screen_width - pos.x;
        }

        if (pos.y < 0) {
            dy = -pos.y;
            is_out_of_bounds = true;
        } else if (pos.y > screen_height) {
            is_out_of_bounds = true;
            dy = screen_height - pos.y;
        }
    }

    if (is_out_of_bounds) {
        pos.x += dx;
        pos.y += dy;
        _tri->set_position(pos);
    }
}

/* #endregion  --------------------------------- [ Check Screen Bounds ] -----------------------------------*/

/* #region  --------------------------------- [ Check 2 OBJ Collision ] -----------------------------------*/

void CollisionHandler::object_type_splitter(Object *_objA, Object *_objB) {
    ObjectType typeA = _objA->type;
    ObjectType typeB = _objB->type;

    switch (typeA) {
    case OBJECT:
        switch (typeB) {
        case OBJECT:
            check_collision(_objA, _objB);
            break;
        case RECT:
            check_collision(_objA, dynamic_cast<Rect *>(_objB));
            break;
        case CIRCLE:
            check_collision(_objA, dynamic_cast<Circle *>(_objB));
            break;
        case TRIANGLE:
            check_collision(_objA, dynamic_cast<Triangle *>(_objB));
            break;
        }
        break;
    case RECT:
        switch (typeB) {
        case OBJECT:
            check_collision(_objB, dynamic_cast<Rect *>(_objA));
            break;
        case RECT:
            check_collision(dynamic_cast<Rect *>(_objA), dynamic_cast<Rect *>(_objB));
            break;
        case CIRCLE:
            check_collision(dynamic_cast<Rect *>(_objA), dynamic_cast<Circle *>(_objB));
            break;
        case TRIANGLE:
            check_collision(dynamic_cast<Rect *>(_objA), dynamic_cast<Triangle *>(_objB));
            break;
        }
        break;
    case CIRCLE:
        switch (typeB) {
        case OBJECT:
            check_collision(_objB, dynamic_cast<Circle *>(_objA));
            break;
        case RECT:
            check_collision(dynamic_cast<Rect *>(_objB), dynamic_cast<Circle *>(_objA));
            break;
        case CIRCLE:
            check_collision(dynamic_cast<Circle *>(_objA), dynamic_cast<Circle *>(_objB));
            break;
        case TRIANGLE:
            check_collision(dynamic_cast<Circle *>(_objA), dynamic_cast<Triangle *>(_objB));
            break;
        }
        break;
    case TRIANGLE:
        switch (typeB) {
        case OBJECT:
            check_collision(_objB, dynamic_cast<Triangle *>(_objA));
            break;
        case RECT:
            check_collision(dynamic_cast<Rect *>(_objB), dynamic_cast<Triangle *>(_objA));
            break;
        case CIRCLE:
            check_collision(dynamic_cast<Circle *>(_objA), dynamic_cast<Triangle *>(_objB));
            break;
        case TRIANGLE:
            check_collision(dynamic_cast<Triangle *>(_objA), dynamic_cast<Triangle *>(_objB));
            break;
        }
        break;
    }
}

bool CollisionHandler::check_collision(Object *_objA, Object *_objB) {
    return false;
}
bool CollisionHandler::check_collision(Object *_objA, Rect *_rectB) {
    return false;
}
bool CollisionHandler::check_collision(Object *_objA, Circle *_circleB) {
    return false;
}
bool CollisionHandler::check_collision(Object *_obj1, Triangle *_triB) {
    return false;
}

bool CollisionHandler::check_collision(Rect *_rectA, Rect *_rectB) {
    return false;
}
bool CollisionHandler::check_collision(Rect *_rectA, Circle *_circleB) {
    return false;
}
bool CollisionHandler::check_collision(Rect *_rectA, Triangle *_triB) {
    return false;
}

bool CollisionHandler::check_collision(Circle *_circleA, Circle *_circleB) {
    SDL_FPoint posA = _circleA->pos;
    SDL_FPoint posB = _circleB->pos;

    float dx = posB.x - posA.x;
    float dy = posB.y - posA.y;

    float rad = _circleA->radius + _circleB->radius;
    float dist = sqrt(dx * dx + dy * dy);

    if (dist < rad) {
        return true;
    }

    return false;
}
bool CollisionHandler::check_collision(Circle *_circleA, Triangle *_triB) {
    return false;
}

bool CollisionHandler::check_collision(Triangle *_triA, Triangle *_triB) {
    return false;
}

/* #endregion --------------------------------- [ Check 2 OBJ Collision ] -----------------------------------*/