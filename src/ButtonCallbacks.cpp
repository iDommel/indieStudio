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
    ButtonCallbacks::ButtonCallbacks(std::function<void(SceneManager &, std::shared_ptr<IEntity>)> pressed,
                                     std::function<void(SceneManager &, std::shared_ptr<IEntity>)> released,
                                     std::function<void(SceneManager &, std::shared_ptr<IEntity>)> down)
        : pressed(pressed),
          released(released),
          down(down)
    {
    }

    ButtonCallbacks::~ButtonCallbacks()
    {
    }
}  // namespace indie
