#include "player.h"

void update_player_camera(Camera3D *camera, const Player *player) {
    camera->position = player->entity.position;
    camera->target   = player->entity.target;
}
