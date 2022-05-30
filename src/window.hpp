/*
** EPITECH PROJECT, 2022
** indieStudio [WSL : Ubuntu]
** File description:
** window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_
#include <string>
#include <vector>
#include <iostream>
#include <raylib.h>

namespace indie {
    class window
    {
    private:
    public:
        /// @brief Construct a new window:: window object with the size of the screen
        window(int screenWidth = GetMonitorWidth(0), int screenHeight = GetMonitorHeight(0));
        /// @brief Destruct the window:: close the windows
        ~window();
        /// @brief function that get the key pressed
        int getKeyPressed();
        void beginDraw();
        /// @brief funcion that clear the background
        void clearBackground();
        /// @brief final function of the loop, end the drawing
        void endDraw();
        /// @brief get the mouse position
        Vector2 getMousePosition();
        /// @brief Shows Cursor
        void showCursor();
        ///  @brief Hide Cursor
        void hideCursor();
    };
}

#endif /* !WINDOW_HPP_ */
