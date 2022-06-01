/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** String.hpp
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <string>
#include "Component.hpp"

namespace indie
{

    class Sprite : public Component
    {
    public:
        Sprite(std::string str) : _value(str) { _type = IComponent::Type::SPRITE; }

        std::string getValue() const { return _value; }

        std::any getComponent() const { return *this; }

    private:
        std::string _value;
    };

}

#endif /* !SPRITE_HPP_ */