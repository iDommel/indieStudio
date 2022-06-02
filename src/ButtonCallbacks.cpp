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
        : _pressed(pressed),
          _released(released),
          _down(down)
    {
    }

    ButtonCallbacks::~ButtonCallbacks()
    {
    }
}  // namespace indie
