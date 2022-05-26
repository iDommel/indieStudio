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

        enum class Tags {
            VECTOR,
            TEXT,
            SPRITE,
            MODEL,
            HITBOX,
            MUSIC,
            SOUND
        };

        Tags getTag() const;

        void setTag(Tags tag) { _tag = tag; };

    protected:
        Tags _tag;
    };

}

#endif /* COMPONENT_HPP */