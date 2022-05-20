/*
** EPITECH PROJECT, 2022
** indieStudio [WSL : Ubuntu]
** File description:
** window
*/
#include "window.hpp"
#include <raylib.h>

window::window(){
    const int screenWidth = GetMonitorWidth(0);
    const int screenHeight = GetMonitorHeight(0);

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - basic shapes drawing");
}


window::~window(){
    CloseWindow();
}

void window::loop(){
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        int i = GetKeyPressed();
        std::cout << "key : " << i << std::endl;

        DrawText("testing if it's work", 20, 20, 20, DARKGRAY);
        EndDrawing();
    }
}