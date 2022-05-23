/*
** EPITECH PROJECT, 2022
** indieStudio [WSL : Ubuntu]
** File description:
** window
*/
#include "window.hpp"
#include <raylib.h>

indie::window::window(){
    const int screenWidth = GetMonitorWidth(0);
    const int screenHeight = GetMonitorHeight(0);

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - basic shapes drawing");
}


indie::window::~window(){
        CloseWindow();
}

int indie::window::get_key_pressed(){
    int key = GetKeyPressed();
    return(key);
}


void indie::window::loop(){
    {
        while (!WindowShouldClose())
        {
        BeginDrawing();
        int key = get_key_pressed();
        ClearBackground(RAYWHITE);
        if (key != 0)
            std::cout << "key: " << key << std::endl;
        DrawText("testing if it's work", 20, 20, 20, DARKGRAY);
        EndDrawing();
        }
    }
}