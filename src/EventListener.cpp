/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** EventListener
*/

#include "EventListener.hpp"

#include "raylib.h"
namespace indie
{

    EventListener::EventListener() : Component()
    {
        _type = Type::EVT_LISTENER;
    }

    EventListener::~EventListener()
    {
    }

    void EventListener::addKeyboardEvent(KeyboardKey key, ButtonCallbacks callbacks)
    {
        _keyboardMap[key] = callbacks;
    }

    void EventListener::addMouseEvent(MouseButton key, MouseCallbacks func)
    {
        _mouseMap[key] = func;
    }

    void EventListener::addGamepadEvent(int gamepad, GamepadButton key, ButtonCallbacks func)
    {
        _gamepadMap[gamepad][key] = func;
    }

    void EventListener::addGamepadStickEvent(int gamepad, int axis, std::function<void(float)> func)
    {
        _gamepadStickMap[gamepad][axis] = func;
    }

    std::map<KeyboardKey, ButtonCallbacks> &EventListener::getKeyboardMappings()
    {
        return _keyboardMap;
    }

    std::map<MouseButton, MouseCallbacks> &EventListener::getMouseMappings()
    {
        return _mouseMap;
    }

    std::map<GamepadButton, ButtonCallbacks> &EventListener::getGamepadMappings(int gamepad)
    {
        return _gamepadMap[gamepad];
    }

    std::map<int, std::function<void(float)>> &EventListener::getGamepadStickMappings(int gamepad)
    {
        return _gamepadStickMap[gamepad];
    }

}  // namespace indie