/*
** EPITECH PROJECT, 2022
** B-YEP-400-TLS-4-1-indiestudio-iona.dommel-prioux
** File description:
** main
*/
#include <exception>
#include <iostream>

#include "EventListener.hpp"
#include "raylib.h"

void checkListenerEvents(indie::EventListener &listener)
{
    for (auto &it : listener.getKeyboardMappings()) {
        if (IsKeyPressed(it.first)) {
            it.second._pressed();
            break;
        }
        if (IsKeyDown(it.first)) {
            it.second._down();
            break;
        }
        if (IsKeyReleased(it.first)) {
            it.second._released();
            break;
        }
    }
    for (auto &it : listener.getMouseMappings()) {
        Vector2 pos = GetMousePosition();
        if (IsMouseButtonPressed(it.first)) {
            it.second._pressed(pos);
            break;
        }
        if (IsMouseButtonDown(it.first)) {
            it.second._down(pos);
            break;
        }
        if (IsMouseButtonReleased(it.first)) {
            it.second._released(pos);
            break;
        }
        if (IsMouseButtonUp(it.first)) {
            it.second._up(pos);
            break;
        }
    }
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    indie::EventListener listener;

    listener.addKeyboardEvent(KEY_A, {[]() {
                                          std::cout << "A pressed" << std::endl;
                                      },
                                      []() {
                                          std::cout << "A released" << std::endl;
                                      },
                                      []() {
                                          std::cout << "A down" << std::endl;
                                      }});

    listener.addKeyboardEvent(KEY_E, {[]() {
                                          std::cout << "E pressed" << std::endl;
                                      },
                                      []() {
                                          std::cout << "E released" << std::endl;
                                      },
                                      []() {
                                          std::cout << "E down" << std::endl;
                                      }});

    listener.addMouseEvent(MOUSE_LEFT_BUTTON, {[](Vector2 pos) {
                                                   std::cout << "Left mouse button pressed at x: " << pos.x << " y: " << pos.y << std::endl;
                                               },
                                               [](Vector2 pos) {
                                                   std::cout << "Left mouse button released at x: " << pos.x << " y: " << pos.y << std::endl;
                                               },
                                               [](Vector2 pos) {
                                                   std::cout << "Left mouse button down at x: " << pos.x << " y: " << pos.y << std::endl;
                                               },
                                               [](Vector2 pos) {
                                                   std::cout << "Left mouse button up at x: " << pos.x << " y: " << pos.y << std::endl;
                                               }});

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    while (!WindowShouldClose())  // Detect window close button or ESC key
    {
        checkListenerEvents(listener);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();  // Close window and OpenGL context

    return 0;
}