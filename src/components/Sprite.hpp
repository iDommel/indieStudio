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
        Sprite(std::string str, int nbFrame = 0) : _value(str), _nbFrame(nbFrame) { _type = IComponent::Type::SPRITE; }

        std::string getValue() const { return _value; }
        int getNbFrame() { return _nbFrame; }

    private:
        std::string _value;
        int _nbFrame;
    };

}

#endif /* !SPRITE_HPP */