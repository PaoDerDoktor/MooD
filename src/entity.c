#include "entity.h"

#include "raymath.h"

Vector3 move_entity(Entity *entity, const Vector3 *amount) {
    Vector3 oldPosition = entity->position;

    entity->position = Vector3Add(entity->position, *amount);
    entity->target   = Vector3Add(entity->target,   *amount); // Offsetting target too, may recconsider if really needed

    return oldPosition;
}
