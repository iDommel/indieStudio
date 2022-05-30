/*
** EPITECH PROJECT, 2022
** indieStudio [WSL : Ubuntu]
** File description:
** window
*/
#include "Window.hpp"


indie::Window::Window(int screenWidth, int screenHeight, const std::string & name ) {
    InitWindow(screenWidth, screenHeight, name.c_str());
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

void indie::Window::beginMode3D(Camera3D camera) {
    BeginMode3D(camera);
}

void indie::Window::beginMode2D(Camera2D camera) {
    BeginMode2D(camera);
}

void indie::Window::endMode3D() {
    EndMode3D();
}

void indie::Window::endMode2D() {
    EndMode2D();
}