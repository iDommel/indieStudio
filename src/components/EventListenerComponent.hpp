/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** EventListenerComponent
*/

#ifndef EVENTLISTENERCOMPONENT_HPP_
#define EVENTLISTENERCOMPONENT_HPP_
#include "Component.hpp"
#include "EventListener.hpp"
namespace indie
{

    class EventListenerComponent : public Component
    {
    public:
        EventListenerComponent(EventListener &_listener) : _listener(_listener){};

    protected:
    private:
        EventListener _listener;
    };
}  // namespace indie

#endif /* !EVENTLISTENERCOMPONENT_HPP_ */
