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
    class Window
    {
    private:
    public:
        /// @brief Construct a new window:: window object with the size of the screen
        Window(int screenWidth = GetMonitorWidth(0), int screenHeight = GetMonitorHeight(0), char *name = "test");
        /// @brief Destruct the window:: close the windows
        ~Window();
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
        /*
        * @brief Begin 3D mode with custum camera
        * @param camera
        */
        void beginMode3D(Camera3D camera);
        /*
        * @brief Begin 2D mode with custum camera
        * @param camera
        */
        void beginMode2D(Camera2D camera);
        // @brief End 3D mode.
        void endMode3D();
        // @brief End 2D mode.
        void endMode2D();
    };
}

#endif /* !WINDOW_HPP_ */
