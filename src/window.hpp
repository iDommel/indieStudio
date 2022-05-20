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


class window
{
private:
    /* data */
public:
    window();
    ~window();
    void loop();
    void get_key_pressed(int key);
};

#endif /* !WINDOW_HPP_ */
