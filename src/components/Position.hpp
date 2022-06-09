/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Position.hpp
*/

#ifndef POSITION_HPP
#define POSITION_HPP

#include <tuple>

#include "Component.hpp"

namespace indie
{

    class Position : public Component
    {
    public:
        Position(float x, float y, float z = 0) : x(x), y(y), z(z) { _type = IComponent::Type::VECTOR; }

        std::tuple<double, double, double> getPosition() const { return std::make_tuple(x, y, z); }
        void setOrdinate(double _y) { _y = y; }
        void setAbscissa(double _x) { _x = x; }
        double getOrdinate() const { return y; }
        double getAbscissa() const { return x; }
        void setPosition(float newX, float newY, float newZ) { x = newX; y = newY; z = newZ; }

        float x;
        float y;
        float z;
    };
}

#endif /* !POSITION_HPP */
