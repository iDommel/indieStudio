/*
** EPITECH PROJECT, 2022
** B-YEP-400-TLS-4-1-indiestudio-iona.dommel-prioux
** File description:
** main
*/
#include <exception>
#include <iostream>

#include "raylib.h"
#include "collide.hpp"

int test_collide_raylib(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [models] example - box collisions");

    // Define the camera to look into our 3d world
    Camera camera = { { 0.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };

    Vector3 playerPosition = { 0.0f, 1.0f, 2.0f };
    Vector3 playerSize = { 1.0f, 2.0f, 1.0f };
    Color playerColor = GREEN;
    //create player position and size 2d
    Vector2 playerPosition2d = { 15.0f, 15.0f };
    float playerSize2d = 4.0f;
    Color playerColor2d = GREEN;

    Vector3 enemyBoxPos = { -4.0f, 1.0f, 0.0f };
    Vector3 enemyBoxSize = { 2.0f, 2.0f, 0.0f };

    Vector3 enemySpherePos = { 4.0f, 0.0f, 0.0f };
    float enemySphereSize = 1.5f;

    // create a circle to test collision
    Vector2 circlePos = { 20.0f, 20.0f};
    float circleRadius = 10.0f;

    // create a rectangle to test collision
    Rectangle rect = { 10.0f, 0.0f, 10.0f, 10.0f };

    bool collision = false;
    bool collision2d = false;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        // Move player
        if (IsKeyDown(KEY_RIGHT)) {
            playerPosition.x += 0.2f;
            playerPosition2d.x += 2.0f;
        } else if (IsKeyDown(KEY_LEFT)) {
            playerPosition.x -= 0.2f;
            playerPosition2d.x -= 2.0f;
        }
        if (IsKeyDown(KEY_DOWN)) {
            playerPosition.z += 0.2f;
            playerPosition2d.y += 2.0f;
        } else if (IsKeyDown(KEY_UP)) {
            playerPosition.z -= 0.2f;
            playerPosition2d.y -= 2.0f;
        }
        collision = false;
        collision2d = false;

        // Check collisions player vs enemy-box
        if (indie::collide::check3DCollision(
            (BoundingBox){(Vector3){ playerPosition.x - playerSize.x/2,
                                     playerPosition.y - playerSize.y/2,
                                     playerPosition.z - playerSize.z/2 },
                          (Vector3){ playerPosition.x + playerSize.x/2,
                                     playerPosition.y + playerSize.y/2,
                                     playerPosition.z + playerSize.z/2 }},
            (BoundingBox){(Vector3){ enemyBoxPos.x - enemyBoxSize.x/2,
                                     enemyBoxPos.y - enemyBoxSize.y/2,
                                     enemyBoxPos.z - enemyBoxSize.z/2 },
                          (Vector3){ enemyBoxPos.x + enemyBoxSize.x/2,
                                     enemyBoxPos.y + enemyBoxSize.y/2,
                                     enemyBoxPos.z + enemyBoxSize.z/2 }}))
            collision = true;

        // Check collisions player vs enemy-sphere
        if (indie::collide::check3DCollision(
            (BoundingBox){(Vector3){ playerPosition.x - playerSize.x/2,
                                     playerPosition.y - playerSize.y/2,
                                     playerPosition.z - playerSize.z/2 },
                          (Vector3){ playerPosition.x + playerSize.x/2,
                                     playerPosition.y + playerSize.y/2,
                                     playerPosition.z + playerSize.z/2 }},
            enemySpherePos, enemySphereSize))
                collision = true;

         // Check collisions player vs rectangle
        if (indie::collide::check2DCollision(
         playerPosition2d, playerSize2d, rect))
            collision2d = true;

        // Check collisions player vs circle
        if (CheckCollisionCircles(
         playerPosition2d, playerSize2d, circlePos, circleRadius))
            collision2d = true;

        if (collision) playerColor = RED;
        else playerColor = GREEN;
        if (collision2d) playerColor2d = RED;
        else playerColor2d = GREEN;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                // Draw enemy-box
                DrawCube(enemyBoxPos, enemyBoxSize.x, enemyBoxSize.y, enemyBoxSize.z, GRAY);
                DrawCubeWires(enemyBoxPos, enemyBoxSize.x, enemyBoxSize.y, enemyBoxSize.z, DARKGRAY);

                // Draw enemy-sphere
                DrawSphere(enemySpherePos, enemySphereSize, GRAY);
                DrawSphereWires(enemySpherePos, enemySphereSize, 16, 16, DARKGRAY);

                // Draw player
                DrawCubeV(playerPosition, playerSize, playerColor);

                DrawGrid(10, 1.0f);        // Draw a grid

            EndMode3D();

            DrawCircle(circlePos.x, circlePos.y, circleRadius, GREEN);
            DrawRectangle(rect.x, rect.y, rect.width, rect.height, RED);
            DrawCircle(playerPosition2d.x, playerPosition2d.y, playerSize2d, playerColor2d);
            DrawText("Move player with arrows to collide", 220, 40, 20, GRAY);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

int main(void)
{
    return test_collide_raylib();
}