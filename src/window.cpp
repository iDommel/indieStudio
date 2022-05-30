/*
** EPITECH PROJECT, 2022
** indieStudio [WSL : Ubuntu]
** File description:
** window
*/
#include "Window.hpp"


indie::Window::Window(int screenWidth, int screenHeight, char *name) {
    InitWindow(screenWidth, screenHeight, name);
}


indie::Window::~Window(){
        CloseWindow();
}


int indie::Window::getKeyPressed(){
    int key = GetKeyPressed();
    return(key);
}

void indie::Window::beginDraw(){
        BeginDrawing();
}

void indie::Window::clearBackground() {
    ClearBackground(LIGHTGRAY);
}

void indie::Window::endDraw() {
    EndDrawing();
}

Vector2 indie::Window::getMousePosition() {
    Vector2 mp = { 0,0 };
    mp = GetMousePosition();
    return (mp);
}

void indie::Window::showCursor() {
    ShowCursor();
}

void indie::Window::hideCursor() {
    HideCursor();
}
