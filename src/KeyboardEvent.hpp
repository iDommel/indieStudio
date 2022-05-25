/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** KeyBoardEvent
*/

#ifndef KEYBOARDEVENT_HPP_
#define KEYBOARDEVENT_HPP_
#include "IEvent.hpp"

namespace indie
{

    class KeyboardEvent : public IEvent

    {
    public:
        /**
         * @brief Construct a new Keyboard Event object
         *
         * @param key the keycode of the key pressed
         * @param isPressed has the key been pressed once
         * @param isReleased has the key been release once
         * @param isDown is the key down
         */
        KeyboardEvent(int key, bool isPressed, bool isReleased, bool isDown);
        ~KeyboardEvent();
        /// @brief get the keycode of the key pressed
        int getKey() const;
        /// @brief get if the key has been pressed once
        bool isPressed() const;
        /// @brief get if the key has been released once
        bool isReleased() const;
        /// @brief get if the key is down
        bool isDown() const;

    protected:
    private:
        int _key;
        bool _isPressed = false;
        bool _isDown = false;
        bool _isReleased = false;
    };
}  // namespace indie

#endif /* !KEYBOARDEVENT_HPP_ */
