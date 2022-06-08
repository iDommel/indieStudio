/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** AComponent.cpp
*/

#include "Component.hpp"

namespace indie
{
    Component::Component(Type type) : _type(type), _parent(nullptr)
    {
    }

    Component::Type Component::getType() const
    {
        return _type;
    }

}