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
        Position(double x, double y, double z = 0) : Component(Type::VECTOR), _x(x), _y(y), _z(z) {}

        std::tuple<double, double, double> getPosition() const { return std::make_tuple(_x, _y, _z); }
        void setPosition(double x, double y, double z) { _x = x; _y = y; _z = z; }
        void setOrdinate(double y) { _y = y; }
        void setAbscissa(double x) { _x = x; }

    private:
        double _x;
        double _y;
        double _z;
    };

}

#endif /* !POSITION_HPP */