/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** AComponent.hpp
*/

#ifndef COMPONENT_HPP
#define COMPONENT_HPP

namespace indie {

    class Component
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

        Type getType() const;

        void setType(Type type) { _type = type; };

    protected:
        Type _type;
    };

}

#endif /* COMPONENT_HPP */