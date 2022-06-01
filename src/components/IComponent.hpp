/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** IComponent.hpp
*/

#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP

#include <any>

namespace indie
{

    class IComponent
    {
    public:

        enum class Type {
            VECTOR,
            TEXT,
            SPRITE,
            MODEL,
            HITBOX,
            MUSIC,
            SOUND,
            EVT_LISTENER
        };

        virtual Type getType() const = 0;

        virtual std::any getComponent() const = 0;
    };

}

#endif /* ICOMPONENT_HPP */