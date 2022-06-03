/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** String.hpp
*/

#ifndef SPRITEHPP
#define SPRITEHPP

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

#endif /* !SPRITEHPP */