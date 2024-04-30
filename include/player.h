#pragma once

#include "raylib.h"

#include "entity.h"

typedef struct Player {
    Entity entity; 
} Player;

void update_player_camera(Camera3D *camera, const Player *player);
