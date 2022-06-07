/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Position
*/

#include "Position.hpp"

namespace indie
{
    Position::Position(float x, float y, float z)
        : AVector(Component::Type::POSITION, x, y, z)
    {
    }

}  // namespace indie
