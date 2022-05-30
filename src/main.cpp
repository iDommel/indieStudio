/*
** EPITECH PROJECT, 2022
** B-YEP-400-TLS-4-1-indiestudio-iona.dommel-prioux
** File description:
** main
*/
#include <exception>
#include <iostream>
#include "window.hpp"

int main(void)
{
    indie::window win;

    while (!WindowShouldClose())
    {
        Vector2 mp;
        int key = 0;
        win.beginDraw();
        win.clearBackground();
        key = win.getKeyPressed();
        mp = win.getMousePosition();
        if (key != 0)
            std::cout << "key pressed : " << key << std::endl;
        win.endDraw();
    }
    return 0;
}