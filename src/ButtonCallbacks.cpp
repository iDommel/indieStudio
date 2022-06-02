/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** ButtonCallbacks
*/

#include "ButtonCallbacks.hpp"

namespace indie
{

    ButtonCallbacks::ButtonCallbacks()
    {
    }
    ButtonCallbacks::ButtonCallbacks(std::function<void(void)> pressed,
                                     std::function<void(void)> released,
                                     std::function<void(void)> down)
        : pressed(pressed),
          released(released),
          down(down)
    {
    }

    ButtonCallbacks::~ButtonCallbacks()
    {
    }
}  // namespace indie
