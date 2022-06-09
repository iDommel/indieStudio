/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Cube.cpp
*/

#include "raylib.h"
#include "Cube.hpp"

namespace indie
{
    Cube::Cube(Vector3 size, Color color) : _size(size), _color(color)
    {
        _type = Type::CUBE;
    }

    Color &Cube::getColor()
    {
        return _color;
    }

    Vector3 &Cube::getSize()
    {
        return _size;
    }
}