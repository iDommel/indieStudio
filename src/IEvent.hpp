/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** IEvent
*/

#ifndef IEVENT_HPP_
#define IEVENT_HPP_
#include <string>

namespace indie
{

    class IEvent
    {
    public:
        virtual ~IEvent() = default;

    protected:
        IEvent() = default;

    private:
    };
}  // namespace indie

#endif /* !IEVENT_HPP_ */
