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

bool indie::Window::isMouseButtonPressed(int button) {
    IsMouseButtonPressed(button);
}

bool indie::Window::isMouseButtonDown(int button) {
    IsMouseButtonDown(button);
}

bool indie::Window::isMouseButtonReleased(int button) {
    IsMouseButtonReleased(button);
}

bool indie::Window::isMouseButtonUp(int button) {
    IsMouseButtonUp(button);
}

bool indie::Window::isGamepadAvailable(int gamepad) {
    IsGamepadAvailable(gamepad);
}

const char* indie::Window::getGamepadName(int gamepad) {
    GetGamepadName(gamepad);
}

bool indie::Window::isGamepadButtonPressed(int gamepad, int button) {
    IsGamepadButtonPressed(gamepad, button);
}

bool indie::Window::isGamepadButtonDown(int gamepad, int button) {
    IsGamepadButtonDown(gamepad, button);
}

bool indie::Window::isGamepadButtonReleased(int gamepad, int button) {
    IsGamepadButtonReleased(gamepad, button);
}

bool indie::Window::isGamepadButtonUp(int gamepad, int button) {
    IsGamepadButtonUp(gamepad, button);
}

int indie::Window::getGamepadButtonPressed(void) {
    GetGamepadButtonPressed();
}

int indie::Window::getGamepadAxisCount(int gamepad) {
    GetGamepadAxisCount(gamepad);
}

float indie::Window::getGamepadAxisMovement(int gamepad, int axis) {
    GetGamepadAxisMovement(gamepad, axis);
}

int indie::Window::setGamepadMappings(const char* mappings) {
    SetGamepadMappings(mappings)
}

bool indie::Window::isKeyPressed(int key) {
    IsKeyPressed(key);
}
bool indie::Window::isKeyDown(int key) {
    IsKeyDown(key);
}
bool indie::Window::isKeyReleased(int key) {
    IsKeyReleased(key);
}
bool indie::Window::isKeyUp(int key) {
    IsKeyUp(key);
}
void indie::Window::setExitKey(int key) {
    SetExitKey(key);
}