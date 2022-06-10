/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Grid.cpp
*/

#include "raylib.h"
#include "Grid.hpp"

namespace indie
{
    Grid::Grid(int slices, float spacing) : _slices(slices), _spacing(spacing)
    {
        _type = Type::GRID;
    }

    int &Grid::getSlices()
    {
        return _slices;
    }

    float Grid::getSpacing()
    {
        return _spacing;
    }
}