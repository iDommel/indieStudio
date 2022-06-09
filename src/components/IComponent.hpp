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
            EVT_LISTENER,
            RECT,
            CAMERA,
            SPHERE,
            CUBE,
            GRID
        };

        virtual Type getType() const = 0;
    };

}

#endif /* ICOMPONENT_HPP */