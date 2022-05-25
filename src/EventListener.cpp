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

    void EventListener::addKeyboardEvent(KeyboardKey key, KeyboardCallbacks callbacks)
    {
        _keyboardMap[key] = callbacks;
    }

    void EventListener::addMouseEvent(MouseButton key, std::function<void(void)> func)
    {
        _mouseMap[key] = func;
    }

    void EventListener::addGamepadEvent(int gamepad, GamepadButton key, std::function<void(void)> func)
    {
        _gamepadMap[gamepad][key] = func;
    }

    std::map<KeyboardKey, KeyboardCallbacks> &EventListener::getKeyboardMappings()
    {
        return _keyboardMap;
    }

    std::map<MouseButton, std::function<void(void)>> &EventListener::getMouseMappings()
    {
        return _mouseMap;
    }

    std::map<GamepadButton, std::function<void(void)>> &EventListener::getGamepadMappings(int gamepad)
    {
        return _gamepadMap[gamepad];
    }

}  // namespace indie