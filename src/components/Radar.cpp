/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Radar
*/

#include "Radar.hpp"
#include "AVector.hpp"
#include "raylib.h"

namespace indie
{
    Radar::Radar(BoundingBox box, Vector3 pos) : Component(Type::RADAR),
                                                   _box(std::make_unique<BoundingBox>(box))
    {
        _box->min = {pos.x + _box->min.x, pos.y + _box->min.y, pos.z + _box->min.z};
        _box->max = {pos.x + _box->max.x, pos.y + _box->max.y, pos.z + _box->max.z};
        _isInitialized = true;
    }

    Radar::Radar(BoundingBox box) : Component(Type::RADAR), _box(std::make_unique<BoundingBox>(box))
    {
        _isInitialized = true;
    }

    BoundingBox Radar::getBBox(void) const
    {
        return *_box;
    }

    void Radar::setBBox(BoundingBox box)
    {
        _box = std::make_unique<BoundingBox>(box);
    }

    Radar &Radar::operator+=(const AVector shift)
    {
        if (_box) {
            _box->min.x += shift.x;
            _box->min.y += shift.y;
            _box->min.z += shift.z;
            _box->max.x += shift.x;
            _box->max.y += shift.y;
            _box->max.z += shift.z;
        }
        return (*this);
    }

    Radar &Radar::operator-=(const AVector shift)
    {
        if (_box) {
            _box->min.x -= shift.x;
            _box->min.y -= shift.y;
            _box->min.z -= shift.z;
            _box->max.x -= shift.x;
            _box->max.y -= shift.y;
            _box->max.z -= shift.z;
        }
        return (*this);
    }

}