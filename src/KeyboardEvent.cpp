/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** KeyboardEvent
*/

#include "KeyboardEvent.hpp"

namespace indie
{
    KeyboardEvent::KeyboardEvent(int, bool, bool, bool)
    {
    }

    KeyboardEvent::~KeyboardEvent()
    {
    }

    int KeyboardEvent::getKey() const
    {
        return _key;
    }

    bool KeyboardEvent::isPressed() const
    {
        return _isPressed;
    }

    bool KeyboardEvent::isReleased() const
    {
        return _isReleased;
    }

    bool KeyboardEvent::isDown() const
    {
        return _isDown;
    }

}  // namespace indie
