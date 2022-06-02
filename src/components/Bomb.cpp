/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** Bomb
*/

#include "Bomb.hpp"

namespace indie {

Bomb::Bomb(int blastPower)
{
    _blastPower = blastPower;
    _isActive = true;
}

Bomb::~Bomb()
{
}

void Bomb::explode()
{
    if (_seconds >= 2)
        _isActive = false;
}

}
