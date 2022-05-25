/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** EventListener
*/

#ifndef EVENTLISTENER_HPP_
#define EVENTLISTENER_HPP_
#include <functional>
#include <map>

#include "KeyboardCallbacks.hpp"
#include "raylib.h"
namespace indie
{

    class EventListener
    {
    public:
        EventListener();
        ~EventListener();
        /**
         * @brief Adds a keyboard event to the listener
         *
         * @param key the key to listen to
         * @param callsbacks the callbacks to call when the key is interacted with
         */
        void addKeyboardEvent(KeyboardKey key, KeyboardCallbacks callbacks);
        /**
         * @brief Adds a mouse event to the listener
         *
         * @param key the key to listen to
         * @param func the function to call when the key is pressed
         */
        void addMouseEvent(MouseButton key, std::function<void(void)> func);
        /**
         * @brief Adds a gamepad event to the listener
         *
         * @param gamepad the gamepad fow which the events are listened to
         * @param key the key to listen to
         * @param func the function to call when the key is pressed
         */
        void addGamepadEvent(int gamepad, GamepadButton key, std::function<void(void)> func);
        /// @brief gets a reference to the keyboard mappings
        std::map<KeyboardKey, KeyboardCallbacks> &getKeyboardMappings();
        /// @brief gets a reference to the mouse mappings
        std::map<MouseButton, std::function<void(void)>> &getMouseMappings();
        /// @brief gets a reference to the gamepad mappings of a specified gamepad
        std::map<GamepadButton, std::function<void(void)>> &getGamepadMappings(int gamepad);

    protected:
    private:
        std::map<KeyboardKey, KeyboardCallbacks> _keyboardMap;
        std::map<KeyboardKey, std::function<void()>> _keyboardCharMap;
        std::map<MouseButton, std::function<void()>> _mouseMap;
        std::map<int, std::map<GamepadButton, std::function<void()>>> _gamepadMap;
    };
}  // namespace indie

#endif /* !EVENTLISTENER_HPP_ */
