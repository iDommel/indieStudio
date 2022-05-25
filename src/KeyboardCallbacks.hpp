/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** KeyboardCallbacks
*/

#ifndef KEYBOARDCALLBACKS_HPP_
#define KEYBOARDCALLBACKS_HPP_

#include <functional>
namespace indie
{
    /// @brief Class to group all three callbacks for a keyboard event
    class KeyboardCallbacks
    {
    public:
        KeyboardCallbacks();
        /**
         * @brief Construct a new Keyboard Callbacks object
         *
         * @param pressed callback to be called when a key is pressed
         * @param released callback to be called when a key is released
         * @param down callack to be called when a key is down
         */
        KeyboardCallbacks(std::function<void(void)> pressed,
                          std::function<void(void)> released,
                          std::function<void(void)> down);
        ~KeyboardCallbacks();
        std::function<void()> _pressed;
        std::function<void()> _released;
        std::function<void()> _down;

    protected:
    private:
    };
}  // namespace indie

#endif /* !KEYBOARDCALLBACKS_HPP_ */
