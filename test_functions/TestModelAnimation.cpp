#include "raylib.h"
#include "../src/ModelAnimation.hpp"

void test_raylib_modelAnimation()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [models] example - model animation");

    Camera camera = {0};
    camera.position = (Vector3){10.0f, 10.0f, 10.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Model model = LoadModel("assets_test/guy.iqm");
    Texture2D texture = LoadTexture("assets_test/guytex.png");
    SetMaterialTexture(&model.materials[0], MATERIAL_MAP_DIFFUSE, texture);

    Vector3 position = {0.0f, 0.0f, 0.0f};

    unsigned int animsCount = 0;
    indie::ModelAnimation anim("assets_test/guyanim.iqm", &animsCount);
    int animFrameCounter = 0;

    SetCameraMode(camera, CAMERA_FREE);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera);

        if (IsKeyDown(KEY_SPACE))
        {
            animFrameCounter++;
            anim.updateModelAnimation(model, animFrameCounter);
            if (animFrameCounter >= anim.getFrameCount())
                animFrameCounter = 0;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawModelEx(model, position, (Vector3){1.0f, 0.0f, 0.0f}, -90.0f, (Vector3){1.0f, 1.0f, 1.0f}, WHITE);

        DrawGrid(10, 1.0f);

        EndMode3D();

        EndDrawing();
    }
    UnloadTexture(texture);

    anim.unloadModelAnimation();

    UnloadModel(model);

    CloseWindow();
}