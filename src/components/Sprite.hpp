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
        Sprite(std::string str, int x, int y) : _value(str), _x(x), _y(y) { _type = IComponent::Type::SPRITE; }

        std::string getValue() const { return _value; }
        void setValue(std::string str) { _value = str; }
        int getX() const { return _x; }
        int getY() const { return _y; }

    private:
        std::string _value;
        int _x;
        int _y;
    };

}

#endif /* !SPRITE_HPP */