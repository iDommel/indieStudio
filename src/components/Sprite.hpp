/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Sprite.hpp
*/

#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <string>
#include "Component.hpp"

namespace indie
{

    class Sprite : public Component
    {
    public:
        Sprite(std::string str) : _value(str) { _type = IComponent::Type::SPRITE; }

        std::string getValue() const { return _value; }

    private:
        std::string _value;
    };

}

#endif /* !SPRITE_HPP */