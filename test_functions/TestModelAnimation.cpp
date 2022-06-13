#include "raylib.h"
#include "../src/ModelAnimation.hpp"

void test_raylib_modelAnimation()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [models] example - model animation");

    // Define the camera to look into our 3d world
    Vector3 a = { 0.0f, 10.0f, 10.0f };
    Vector3 b = { 0.0f, 0.0f, 0.0f };
    Vector3 c = { 0.0f, 1.0f, 0.0f };
    Camera camera = { a, b, c, 45.0f, 0 };

    Model model = LoadModel("assets_test/guy.iqm");            
    Texture2D texture = LoadTexture("assets_test/guytex.png");       
    SetMaterialTexture(&model.materials[0], MATERIAL_MAP_DIFFUSE, texture);   

    Vector3 position = { 0.0f, 0.0f, 0.0f };      

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
            if (animFrameCounter >= anim.getFrameCount()) animFrameCounter = 0;
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                Vector3 x = { 1.0f, 0.0f, 0.0f };
                Vector3 x2 = { 1.0f, 1.0f, 1.0f };
                DrawModelEx(model, position, x, -90.0f, x2, WHITE);

                DrawGrid(10, 1.0f);

            EndMode3D();

        EndDrawing();
    }
    UnloadTexture(texture); 

    anim.unloadModelAnimation();

    UnloadModel(model); 

    CloseWindow();  
}