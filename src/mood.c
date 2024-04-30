#include "raylib.h"

#include "block.h"
#include "player.h"

int main() {
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "MooD");

    SetTargetFPS(60);

    Player player = {
        .entity = {
            .position   = {0.0f, 0.0f, 0.0f},
            .target     = {0.0f, 0.0f, 1.0f},
            .up         = {0.0f, 1.0f, 0.0f}
        }
    };

    Camera3D playercam = {
        .position   = {0.0f, 0.0f, 0.0f},
        .target     = {0.0f, 0.0f, 1.0f},
        .up         = {0.0f, 1.0f, 0.0f},
        .fovy       = 120.0f,
        .projection = CAMERA_PERSPECTIVE
    };

    Block middleBlock = {
        .type = BTYPE_DEFAULT
    };

    Model     defaultBlockModel   = LoadModel("assets/models/blocks/default.obj");

    Texture2D defaultBlockTexture = load_block_texture(&middleBlock);



    while (!WindowShouldClose()) {
        update_player_camera(&playercam, &player);

        BeginDrawing(); {

            ClearBackground(PINK);

            BeginMode3D(playercam); {

                draw_block(&defaultBlockModel, &defaultBlockTexture, &middleBlock);

            } EndMode3D();

        } EndDrawing();
    }

    // UnloadTexture() and CloseWindow() are called automatically.

    return 0;
}
