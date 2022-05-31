/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** GamepadStickCallbacks
*/

#ifndef GAMEPADCALLBACKS_HPP_
#define GAMEPADCALLBACKS_HPP_
#include <functional>

namespace indie
{
    /// @brief Class to group the gamepad events related to a gamepad's stick movements
    class GamepadStickCallbacks
    {
    public:
        GamepadStickCallbacks();
        /**
         * @brief Construct a new GamepadStickCallbacks object
         *
         * @param negative callback to be called when a gamepad is negative
         * @param null callback to be called when a gamepad is null
         * @param positive callack to be called when a gamepad is positive
         */
        GamepadStickCallbacks(
            std::function<void(float)> negative,
            std::function<void()> null,
            std::function<void(float)> positive);
        ~GamepadStickCallbacks();
        std::function<void(float)> _negative;
        std::function<void()> _null;
        std::function<void(float)> _positive;

    protected:
    private:
    };
}  // namespace indie

#endif /* !GAMEPADCALLBACKS_HPP_ */
