/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** AComponent.cpp
*/

#include <stdexcept>
#include "Component.hpp"

namespace indie
{

    Component::Type Component::getType() const
    {
        return _type;
    }

}