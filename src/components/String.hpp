/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** String.hpp
*/

#pragma once

#include <string>
#include "Component.hpp"

namespace indie
{

    class String : public Component
    {
    public:
        String(std::string str) : _value(str) {}

        std::string getValue() const { return _value; }

    private:
        std::string _value;
    };

}