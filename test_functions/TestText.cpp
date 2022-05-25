/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** TestText
*/

#include <raylib.h>
#include "Text.hpp"

#define MAX_FONTS   8

void TestText(void)
{
        // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [text] example - raylib fonts");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
    Font fonts[MAX_FONTS] = { 0 };
    indie::Text text;

    fonts[0] = LoadFont("test_fonts/alagard.png");
    fonts[1] = LoadFont("test_fonts/pixelplay.png");
    fonts[2] = LoadFont("test_fonts/mecha.png");
    fonts[3] = LoadFont("test_fonts/setback.png");
    fonts[4] = LoadFont("test_fonts/romulus.png");
    fonts[5] = LoadFont("test_fonts/pixantiqua.png");
    fonts[6] = LoadFont("test_fonts/alpha_beta.png");
    fonts[7] = LoadFont("test_fonts/jupiter_crash.png");

    const char *messages[MAX_FONTS] = { "ALAGARD FONT designed by Hewett Tsoi",
                                "PIXELPLAY FONT designed by Aleksander Shevchuk",
                                "MECHA FONT designed by Captain Falcon",
                                "SETBACK FONT designed by Brian Kent (AEnigma)",
                                "ROMULUS FONT designed by Hewett Tsoi",
                                "PIXANTIQUA FONT designed by Gerhard Grossmann",
                                "ALPHA_BETA FONT designed by Brian Kent (AEnigma)",
                                "JUPITER_CRASH FONT designed by Brian Kent (AEnigma)" };

    const int spacings[MAX_FONTS] = { 2, 4, 8, 4, 3, 4, 4, 1 };

    Vector2 positions[MAX_FONTS] = { 0 };

    for (int i = 0; i < MAX_FONTS; i++)
    {
        positions[i].x = screenWidth/2.0f - MeasureTextEx(fonts[i], messages[i], fonts[i].baseSize*2.0f, (float)spacings[i]).x/2.0f;
        positions[i].y = 60.0f + fonts[i].baseSize + 45.0f*i;
    }

    // Small Y position corrections
    positions[3].y += 8;
    positions[4].y += 2;
    positions[7].y -= 8;

    Color colors[MAX_FONTS] = { MAROON, ORANGE, DARKGREEN, DARKBLUE, DARKPURPLE, LIME, GOLD, RED };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            text.DrawText("free fonts included with raylib", 250, 20, 20, DARKGRAY);
            DrawLine(220, 50, 590, 50, DARKGRAY);

            for (int i = 0; i < MAX_FONTS; i++)
            {
                DrawTextEx(fonts[i], messages[i], positions[i], fonts[i].baseSize*2.0f, (float)spacings[i], colors[i]);
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // Fonts unloading
    for (int i = 0; i < MAX_FONTS; i++) UnloadFont(fonts[i]);

    CloseWindow();                 // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

}