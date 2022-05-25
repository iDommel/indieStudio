/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** KeyboardCallbacks
*/

#include "KeyboardCallbacks.hpp"

namespace indie
{

    KeyboardCallbacks::KeyboardCallbacks()
    {
    }
    KeyboardCallbacks::KeyboardCallbacks(std::function<void(void)> pressed,
                                         std::function<void(void)> released,
                                         std::function<void(void)> down)
        : _pressed(pressed),
          _released(released),
          _down(down)
    {
    }

    KeyboardCallbacks::~KeyboardCallbacks()
    {
    }
}  // namespace indie
