/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** ExitEvent
*/

#ifndef EXITEVENT_HPP_
#define EXITEVENT_HPP_
#include "IEvent.hpp"
namespace indie
{

    class ExitEvent : public IEvent
    {
    public:
        ExitEvent();
        ~ExitEvent();

    protected:
    private:
    };
}  // namespace indie
#endif /* !EXITEVENT_HPP_ */
