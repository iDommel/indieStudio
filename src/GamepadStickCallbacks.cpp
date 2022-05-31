/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** GamepadStickCallbacks
*/

#include "GamepadStickCallbacks.hpp"

namespace indie
{
    GamepadStickCallbacks::GamepadStickCallbacks(std::function<void(float)> negative,
                                                 std::function<void()> null,
                                                 std::function<void(float)> positive)
        : _negative(negative),
          _null(null),
          _positive(positive)
    {
    }

    GamepadStickCallbacks::~GamepadStickCallbacks()
    {
    }
}  // namespace indie