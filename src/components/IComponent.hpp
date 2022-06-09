/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** IComponent.hpp
*/

#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP

namespace indie
{

    class IEntity;
    class IComponent
    {
    public:
        enum class Type {
            POSITION,
            VELOCITY,
            TRANSFORM,
            ROTATION,
            TEXT,
            SPRITE,
            MODEL,
            HITBOX,
            MUSIC,
            SOUND,
            EVT_LISTENER,
            PLAYER
        };
        virtual Type getType() const = 0;
    };

}

#endif /* ICOMPONENT_HPP */