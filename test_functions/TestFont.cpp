/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** TestText
*/

#include <raylib.h>
#include <vector>
#include "Font.hpp"

#define MAX_FONTS   8

void TestFont(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [text] example - font loading");

    // Define characters to draw
    // NOTE: raylib supports UTF-8 encoding, following list is actually codified as UTF8 internally
    const char msg[256] = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHI\nJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmn\nopqrstuvwxyz{|}~¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓ\nÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷\nøùúûüýþÿ";

    // NOTE: Textures/Fonts MUST be loaded after Window initialization (OpenGL context is required)

    // BMFont (AngelCode) : Font data and image atlas have been generated using external program
    indie::Font fontBm;
    fontBm.LoadFont("resources/pixantiqua.fnt");

    // TTF font : Font data and atlas are generated directly from TTF
    // NOTE: We define a font base size of 32 pixels tall and up-to 250 characters
    //Font fontTtf = LoadFontEx("resources/pixantiqua.ttf", 32, 0, 250);

    bool useTtf = false;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_SPACE)) useTtf = true;
        else useTtf = false;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Hold SPACE to use TTF generated font", 20, 20, 20, LIGHTGRAY);

            if (!useTtf)
            {
                DrawTextEx(fontBm, msg, (Vector2){ 20.0f, 100.0f }, (float)fontBm.baseSize, 2, MAROON);
                DrawText("Using BMFont (Angelcode) imported", 20, GetScreenHeight() - 30, 20, GRAY);
            }
            else
            {
                DrawTextEx(fontTtf, msg, (Vector2){ 20.0f, 100.0f }, (float)fontTtf.baseSize, 2, LIME);
                DrawText("Using TTF font generated", 20, GetScreenHeight() - 30, 20, GRAY);
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadFont(fontBm);     // AngelCode Font unloading
    UnloadFont(fontTtf);    // TTF Font unloading

    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------


}