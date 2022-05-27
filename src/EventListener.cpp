/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** EventListener
*/

#include "EventListener.hpp"

namespace indie
{

    EventListener::EventListener()
    {
    }

    EventListener::~EventListener()
    {
    }

    void EventListener::addKeyboardEvent(KeyboardKey key, ButtonCallbacks callbacks)
    {
        _keyboardMap[key] = callbacks;
    }

    void EventListener::addMouseEvent(MouseButton key, ButtonCallbacks func)
    {
        _mouseMap[key] = func;
    }

    void EventListener::addGamepadEvent(int gamepad, GamepadButton key, ButtonCallbacks func)
    {
        _gamepadMap[gamepad][key] = func;
    }

    std::map<KeyboardKey, ButtonCallbacks> &EventListener::getKeyboardMappings()
    {
        return _keyboardMap;
    }

    std::map<MouseButton, ButtonCallbacks> &EventListener::getMouseMappings()
    {
        return _mouseMap;
    }

    std::map<GamepadButton, ButtonCallbacks> &EventListener::getGamepadMappings(int gamepad)
    {
        return _gamepadMap[gamepad];
    }

}  // namespace indie