/*
** EPITECH PROJECT, 2022
** indieStudio [WSL : Ubuntu]
** File description:
** window
*/
#include "window.hpp"


indie::window::window(int screenWidth, int screenHeight) {
    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - basic shapes drawing");
}


indie::window::~window(){
        CloseWindow();
}


int indie::window::getKeyPressed(){
    int key = GetKeyPressed();
    return(key);
}

void indie::window::beginDraw(){
        BeginDrawing();
}

void indie::window::clearBackground() {
    ClearBackground(LIGHTGRAY);
}

void indie::window::endDraw() {
    EndDrawing();
}

Vector2 indie::window::getMousePosition() {
    Vector2 mp = { 0,0 };
    mp = GetMousePosition();
    return (mp);
}

void indie::window::showCursor() {
    ShowCursor();
}

void indie::window::hideCursor() {
    HideCursor();
}