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
            /// @brief Describe elements that can touch
            HITBOX,
            /// @brief Describe elements that can be touched
            HURTBOX,
            MUSIC,
            SOUND,
            EVT_LISTENER
        };

        virtual Type getType() const = 0;
    };

}

#endif /* ICOMPONENT_HPP */