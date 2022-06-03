/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Position.hpp
*/

#ifndef POSITIONHPP
#define POSITIONHPP

#include <tuple>

#include "Component.hpp"

namespace indie
{

    class Position : public Component
    {
    public:
        Position(double x, double y, double z = 0) : _x(x), _y(y), _z(z) { _type = IComponent::Type::VECTOR; }

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

#endif /* !POSITIONHPP */