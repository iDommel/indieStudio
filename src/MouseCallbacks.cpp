/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** MouseCallbacks
*/

#include "MouseCallbacks.hpp"

namespace indie
{

    MouseCallbacks::MouseCallbacks()
    {
    }
    MouseCallbacks::MouseCallbacks(std::function<void(Vector2)> pressed,
                                   std::function<void(Vector2)> released,
                                   std::function<void(Vector2)> down,
                                   std::function<void(Vector2)> up)
        : _pressed(pressed),
          _released(released),
          _down(down),
          _up(up)
    {
    }

    MouseCallbacks::~MouseCallbacks()
    {
    }
}  // namespace indie
