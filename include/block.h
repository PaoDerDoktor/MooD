#pragma once

#ifndef MOOD_BLOCK_H
#define MOOD_BLOCK_H

#include <limits.h>
#include <stdint.h>
#include <string.h>

#include "raylib.h"

enum BlockType {
    BTYPE_DEFAULT = 0,
    BTYPE_NONE
};

extern const char *BLOCK_TYPE_NAME_LOOKUP[BTYPE_NONE+1];

typedef struct Block {
    enum BlockType type;
} Block;


void draw_block(Model *blockModel, const Texture2D *texture, const Block *block);

Texture2D load_block_texture(const Block *block);

#endif /* MOOD_BLOCK_H */
