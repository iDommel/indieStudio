/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** ButtonCallbacks
*/

#ifndef BUTTONCALLBACKS_HPP_
#define BUTTONCALLBACKS_HPP_

#include <functional>
namespace indie
{
    /// @brief Class to group all pressed, released and down callbacks for an event
    class ButtonCallbacks
    {
    public:
        ButtonCallbacks();
        /**
         * @brief Construct a new Button Callbacks object
         *
         * @param pressed callback to be called when a button is pressed
         * @param released callback to be called when a button is released
         * @param down callback to be called when a button is down
         */
        ButtonCallbacks(
            std::function<void(void)> pressed,
            std::function<void(void)> released,
            std::function<void(void)> down);
        ~ButtonCallbacks();
        std::function<void()> _pressed;
        std::function<void()> _released;
        std::function<void()> _down;

    protected:
    private:
    };
}  // namespace indie

#endif /* !BUTTONCALLBACKS_HPP_ */
