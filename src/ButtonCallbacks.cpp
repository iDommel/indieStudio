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
    ButtonCallbacks::ButtonCallbacks(std::function<void(SceneManager &)> pressed,
                                     std::function<void(SceneManager &)> released,
                                     std::function<void(SceneManager &)> down)
        : pressed(pressed),
          released(released),
          down(down)
    {
    }

    ButtonCallbacks::~ButtonCallbacks()
    {
    }
}  // namespace indie
