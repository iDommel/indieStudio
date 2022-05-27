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

#include "ButtonCallbacks.hpp"
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
        void addKeyboardEvent(KeyboardKey key, ButtonCallbacks callbacks);
        /**
         * @brief Adds a mouse event to the listener
         *
         * @param key the key to listen to
         * @param func the function to call when the key is pressed
         */
        void addMouseEvent(MouseButton key, ButtonCallbacks func);
        /**
         * @brief Adds a gamepad event to the listener
         *
         * @param gamepad the gamepad fow which the events are listened to
         * @param key the key to listen to
         * @param func the function to call when the key is pressed
         */
        void addGamepadEvent(int gamepad, GamepadButton key, ButtonCallbacks func);
        /// @brief gets a reference to the keyboard mappings
        std::map<KeyboardKey, ButtonCallbacks> &getKeyboardMappings();
        /// @brief gets a reference to the mouse mappings
        std::map<MouseButton, ButtonCallbacks> &getMouseMappings();
        /// @brief gets a reference to the gamepad mappings of a specified gamepad
        std::map<GamepadButton, ButtonCallbacks> &getGamepadMappings(int gamepad);

    protected:
    private:
        std::map<KeyboardKey, ButtonCallbacks> _keyboardMap;
        std::map<char, ButtonCallbacks> _keyboardCharMap;
        std::map<MouseButton, ButtonCallbacks> _mouseMap;
        std::map<int, std::map<GamepadButton, ButtonCallbacks>> _gamepadMap;
    };
}  // namespace indie

#endif /* !EVENTLISTENER_HPP_ */
