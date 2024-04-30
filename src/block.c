#include "block.h"

#include "stdlib.h"
#include "stdio.h"

const char *BLOCK_TYPE_NAME_LOOKUP[BTYPE_NONE+1] = {
    "default",
    "none"
};

void draw_block(Model *blockModel, const Texture2D *texture, const Block *block) {
    blockModel->materials[0].maps[MATERIAL_MAP_ALBEDO].texture = *texture;

    DrawModel(*blockModel, (Vector3){0.0f, -2.0f, 3.0f}, 1.0f, WHITE);
}

Texture2D load_block_texture(const Block *block) {
    char *path = (char *)calloc(256, sizeof(char));
    path[0] = '\0';

    strncat_s(path, 256, "assets/blockTextures/", 22);
    strncat_s(path, 256, BLOCK_TYPE_NAME_LOOKUP[block->type], strnlen_s(BLOCK_TYPE_NAME_LOOKUP[block->type], 235));
    strncat_s(path, 256, ".png", 5);

    Texture2D texture = LoadTexture(path);

    free(path);

    return texture;
}
