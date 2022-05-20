/*
** EPITECH PROJECT, 2022
** B-YEP-400-TLS-4-1-indiestudio-iona.dommel-prioux
** File description:
** main
*/
#include <exception>
#include <iostream>

#include "raylib.h"
#include "IndiCam.hpp"

void test_raylib()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "3d camera encapsulation test");

    std::shared_ptr<Vector3> cubePosition = std::make_shared<Vector3>((Vector3){0.0f, 0.0f, 0.0f});
    std::shared_ptr<Vector3> cameraPosition = std::make_shared<Vector3>((Vector3){0.0f, 10.0f, 10.0f});
    IndiCam camera(cubePosition, cameraPosition);


    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        if (IsKeyDown('Z')) {
            cubePosition->z += 0.1f;
        } else if (IsKeyDown('S')) {
            cubePosition->z -= 0.1f;
        }
        if (IsKeyDown('Q')) {
            cubePosition->x += 0.1f;
        } else if (IsKeyDown('D')) {
            cubePosition->x -= 0.1f;
        }
        if (IsKeyDown('A')) {
            cubePosition->y += 0.1f;
        } else if (IsKeyDown('E')) {
            cubePosition->y -= 0.1f;
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

            DrawText("Free camera default controls:", 20, 20, 10, BLACK);
            DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY);
            DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY);
            DrawText("- Alt + Mouse Wheel Pressed to Rotate", 40, 80, 10, DARKGRAY);
            DrawText("- Alt + Ctrl + Mouse Wheel Pressed for Smooth Zoom", 40, 100, 10, DARKGRAY);
            DrawText("- Z to zoom to (0, 0, 0)", 40, 120, 10, DARKGRAY);

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
    test_raylib();
    return 0;
}