/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Sprite.hpp
*/

#ifndef RECT_HPP
#define RECT_HPP

#include <string>
#include "Component.hpp"

namespace indie
{

    class Rect : public Component
    {
    public:
        Rect(float left = 0, float top = 0, float width = 0, float height = 0) : left(left), top(top), width(width), height(height)
            { _type = IComponent::Type::RECT; }

        float left;
        float top;
        float width;
        float height;
        bool _isInitialized = true;
    };

}

#endif /* !RECT_HPP */