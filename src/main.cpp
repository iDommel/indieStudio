/*
** EPITECH PROJECT, 2022
** B-YEP-400-TLS-4-1-indiestudio-iona.dommel-prioux
** File description:
** main
*/
#include <exception>
#include <iostream>
#include "window.hpp"

#include "raylib.h"
#include "shape3d.hpp"
#include "Camera.hpp"


void test_raylib_shape3D()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    Vector3 cAmeraPosition = {0.0f, 10.0f, 10.0f};
    Vector3 cUbePosition = {0.0f, 0.0f, 0.0f};
  
    indie::Shape3D shape3D;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - basic shapes drawing");

    Camera camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };     // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;                   // Camera mode type

    SetTargetFPS(60);  // Set our game to run at 60 frames-per-second
  
  // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        if (IsKeyDown(KEY_RIGHT)) {
            cubePosition->x -= 0.1f;
        } else if (IsKeyDown(KEY_LEFT)) {
            cubePosition->x += 0.1f;
        }
        if (IsKeyDown(KEY_UP)) {
            cubePosition->y += 0.1f;
        } else if (IsKeyDown(KEY_DOWN)) {
            cubePosition->y -= 0.1f;
        }
        if (IsKeyDown(KEY_RIGHT_SHIFT)) {
            cubePosition->z += 0.1f;
        } else if (IsKeyDown(KEY_RIGHT_CONTROL)) {
            cubePosition->z -= 0.1f;
        }
        if (IsKeyDown(KEY_KP_ADD)) {
            cameraPosition->y += 0.1f;
        } else if (IsKeyDown(KEY_KP_SUBTRACT)) {
            cameraPosition->y -= 0.1f;
        }
        camera.update();          // Update camera
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            camera.beginDrawScope();
      BeginMode3D(camera);

            shape3D.drawSphere({4.0f, 0.0f, 0.0f}, 1.5f, BLACK);
            shape3D.drawCube({0.0f, 0.0f, 0.0f}, {1.5f, 1.5f, 1.5f}, BLACK);
            shape3D.drawGrid(10, 1.0f);

        EndMode3D();
       EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
}

void test_raylib_camera()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    Vector3 cAmeraPosition = {0.0f, 10.0f, 10.0f};
    Vector3 cUbePosition = {0.0f, 0.0f, 0.0f};

    InitWindow(screenWidth, screenHeight, "3d camera encapsulation test");

    std::shared_ptr<Vector3> cubePosition = std::make_shared<Vector3>(cUbePosition);
    std::shared_ptr<Vector3> cameraPosition = std::make_shared<Vector3>(cAmeraPosition);
    indie::Camera camera(cubePosition, cameraPosition);


    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        if (IsKeyDown(KEY_RIGHT)) {
            cubePosition->x -= 0.1f;
        } else if (IsKeyDown(KEY_LEFT)) {
            cubePosition->x += 0.1f;
        }
        if (IsKeyDown(KEY_UP)) {
            cubePosition->y += 0.1f;
        } else if (IsKeyDown(KEY_DOWN)) {
            cubePosition->y -= 0.1f;
        }
        if (IsKeyDown(KEY_RIGHT_SHIFT)) {
            cubePosition->z += 0.1f;
        } else if (IsKeyDown(KEY_RIGHT_CONTROL)) {
            cubePosition->z -= 0.1f;
        }
        if (IsKeyDown(KEY_KP_ADD)) {
            cameraPosition->y += 0.1f;
        } else if (IsKeyDown(KEY_KP_SUBTRACT)) {
            cameraPosition->y -= 0.1f;
        }
        camera.update();          // Update camera
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            camera.beginDrawScope();


                DrawCube(*cubePosition.get(), 2.0f, 2.0f, 2.0f, RED);
                DrawCubeWires(*cubePosition.get(), 2.0f, 2.0f, 2.0f, MAROON);

                DrawGrid(10, 1.0f);

            camera.endDrawScope();

            DrawRectangle( 10, 10, 320, 133, Fade(SKYBLUE, 0.5f));
            DrawRectangleLines( 10, 10, 320, 133, BLUE);

            DrawText("- Use arrows, right-ctrl and right-shift to move the object", 40, 40, 10, DARKGRAY);
            DrawText("- Use + and - to move the cam", 40, 60, 10, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
}

int main(void)
{
    return 0;
}