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
        window();
        ~window();
        void loop();
        int get_key_pressed();
    };
}

#endif /* !WINDOW_HPP_ */
