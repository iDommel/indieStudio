/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Position.hpp
*/

#ifndef POSITION_HPP_
#define POSITION_HPP_

#include "Component.hpp"

namespace indie
{

    class Position : public Component
    {
    public:
        Position(double x, double y) : _x(x), _y(y) { _type = IComponent::Type::VECTOR; }

        std::pair<double, double> getPosition() const { return std::make_pair(_x, _y); }
        void setPosition(double x, double y) { _x = x; _y = y; }
        void setOrdinate(double y) { _y = y; }
        void setAbscissa(double x) { _x = x; }

        std::any getComponent() const { return *this; }

    private:
        double _x;
        double _y;
    };

}

#endif /* !POSITION_HPP_ */