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
#include "Component.hpp"
#include "GamepadStickCallbacks.hpp"
#include "MouseCallbacks.hpp"
#include "raylib.h"
namespace indie
{

    /// @brief EventListener is a class to describe what to do when an event is detected.
    /// you can add a callback to an event by using the different add<>Event methods.
    class EventListener : public Component
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
        void addMouseEvent(MouseButton key, MouseCallbacks func);
        /**
         * @brief Adds a gamepad event to the listener
         *
         * @param gamepad the gamepad fow which the events are listened to
         * @param key the key to listen to
         * @param func the function to call when the key is pressed
         */
        void addGamepadEvent(int gamepad, GamepadButton key, ButtonCallbacks func);
        /**
         * @brief Adds a gamepad stick event to the listener
         *
         * @param gamepad the gamepad fow which the events are listened to
         * @param axis the stick aswell as the axis to listen to
         * @param func a function that will be called on every update to react to the stick position
         */
        void addGamepadStickEvent(int gamepad, int axis, std::function<void(float)> func);
        /// @brief gets a reference to the keyboard mappings
        std::map<KeyboardKey, ButtonCallbacks> &getKeyboardMappings();
        /// @brief gets a reference to the mouse mappings
        std::map<MouseButton, MouseCallbacks> &getMouseMappings();
        /// @brief gets a reference to the gamepad mappings of a specified gamepad
        std::map<GamepadButton, ButtonCallbacks> &getGamepadMappings(int gamepad);
        /// @brief gets a reference to the gamepad stick mappings of a specified gamepad
        std::map<int, std::function<void(float)>> &getGamepadStickMappings(int gamepad);

    protected:
    private:
        std::map<KeyboardKey, ButtonCallbacks> _keyboardMap;
        std::map<char, ButtonCallbacks> _keyboardCharMap;
        std::map<MouseButton, MouseCallbacks> _mouseMap;
        std::map<int, std::map<GamepadButton, ButtonCallbacks>> _gamepadMap;
        std::map<int, std::map<int, std::function<void(float)>>> _gamepadStickMap;
    };
}  // namespace indie

#endif /* !EVENTLISTENER_HPP_ */
