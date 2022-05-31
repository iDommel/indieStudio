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
#include <string>
#include <iostream>
#include <raylib.h>

namespace indie {
    class Window
    {
    private:
    public:
        /// @brief Construct a new window:: window object with the size of the screen
        Window(int screenWidth = GetMonitorWidth(0), int screenHeight = GetMonitorHeight(0), const std::string &name = "test");
        /// @brief Destruct the window:: close the windows
        ~Window();
        /// @brief function that get the key pressed
        int getKeyPressed();
        /// @brief Start window drawing state
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
        /// @brief End 3D mode.
        void endMode3D();
        /// @brief End 2D mode.
        void endMode2D();
        /// @brief Check if a mouse button has been pressed once
        bool isMouseButtonPressed(int button);
        /// @brief Check if a mouse button is being pressed
        bool isMouseButtonDown(int button);
        /// @brief Check if a mouse button has been released once
        bool isMouseButtonReleased(int button);
        /// @brief Check if a mouse button is NOT being pressed
        bool isMouseButtonUp(int button);
        /// @brief Check if a gamepad is available
        bool isGamepadAvailable(int gamepad);
        /// @brief  Get gamepad internal name id
        const char* getGamepadName(int gamepad);
        /// @brief  Check if a gamepad button has been pressed once
        bool isGamepadButtonPressed(int gamepad, int button);
        /// @brief  Check if a gamepad button is being pressed
        bool isGamepadButtonDown(int gamepad, int button);
        /// @brief  Check if a gamepad button has been released once
        bool isGamepadButtonReleased(int gamepad, int button);
        /// @brief  Check if a gamepad button is NOT being pressed
        bool isGamepadButtonUp(int gamepad, int button);
        /// @brief  Get the last gamepad button pressed
        int getGamepadButtonPressed(void);
        /// @brief  Get gamepad axis count for a gamepad
        int getGamepadAxisCount(int gamepad);
        /// @brief  Get axis movement value for a gamepad axis
        float getGamepadAxisMovement(int gamepad, int axis);  
        /// @brief Set internal gamepad mappings (SDL_GameControllerDB)
        int setGamepadMappings(const char* mappings);
        /// @brief Check if a key has been pressed once
        bool isKeyPressed(int key);
        /// @brief Check if a key is being pressed
        bool isKeyDown(int key);
        /// @brief Check if a key has been released once
        bool isKeyReleased(int key);
        /// @brief Check if a key is NOT being pressed
        bool isKeyUp(int key);
        ///  @brief Set a custom key to exit program(default is ESC)
        void setExitKey(int key);
    };
}

#endif /* !WINDOW_HPP_ */
