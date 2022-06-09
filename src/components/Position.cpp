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

    Position::Position(const Position &other)
        : AVector(Component::Type::POSITION, other.x, other.y, other.z)
    {
    }

    Position::Position(const Position &&other)
        : AVector(Component::Type::POSITION, other.x, other.y, other.z)
    {
    }

    void Position::operator=(const AVector &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }

    Position::Position(const AVector &other)
        : AVector(Component::Type::POSITION, other.x, other.y, other.z)
    {
    }
}  // namespace indie
