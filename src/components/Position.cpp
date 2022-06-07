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
        : Component(Component::Type::POSITION), x(x), y(y), z(z)
    {
    }

    std::tuple<float, float, float> Position::getPosition() const
    {
        return std::make_tuple(x, y, z);
    }
}  // namespace indie
