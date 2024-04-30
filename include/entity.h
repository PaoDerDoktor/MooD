#pragma once

#include "raylib.h"

typedef struct Entity {
    Vector3 position;
    Vector3 target;
    Vector3 up;
} Entity;

Vector3 move_entity(Entity *entity, const Vector3 *amount);
