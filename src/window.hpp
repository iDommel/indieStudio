/*
** EPITECH PROJECT, 2022
** indieStudio [WSL : Ubuntu]
** File description:
** window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_
#include <string>
#include <iostream>

namespace indie {
    class window
    {
    private:
    public:
        /// @brief Construct a new window:: window object with the size of the screen
        window();
        /// @brief Destruct the window:: close the windows
        ~window();
        /// @brief game loop
        void loop();
        /// @brief function that get the key pressed
        int get_key_pressed();
    };
}

#endif /* !WINDOW_HPP_ */
